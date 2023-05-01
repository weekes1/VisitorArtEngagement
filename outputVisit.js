var baseUrl = 'http://18.223.238.7:5010';
var state="off";
var loc="Visit";

window.onload = pageLoad();
window.onbeforeunload = pageClose();


var inthandle;
function pageLoad() {
    findLoc(loc)
    inthandle = setInterval(findLoc(loc), 60000)
}

function pageClose() {
    clearInterval(inthandle);
}

function findLoc(loc) {
	fetch(baseUrl+'/engage/findLoc/'+loc, {
        method: 'get'
    })
    .then (response => response.json())
    .then (respJSON => createCanvas(parseColors(respJSON)))
}

function parseColors(response) {
    console.log("In parseColors function");
    let entries = response['users'];
    let colorVec = [];
    for (let userData in entries) {
        colorVec.push(entries[userData][1]);
    }
    return colorVec
}

function createCanvas(colors) {
    colors = colors.sort(() => Math.random() - 0.5);

    const canvas = document.getElementById('myCanvas');
    const ctx = canvas.getContext('2d');

    const canvasWidth = window.innerWidth;
    const canvasHeight = window.innerHeight;

    const numColors = colors.length;
    const perfectSquare = Math.floor(Math.sqrt(numColors));
    const numRows = numColors % perfectSquare === 0 ? perfectSquare : Math.floor(numColors / perfectSquare);
    const numCols = Math.ceil(numColors / numRows);

    const squareSize = Math.min(canvasWidth / numCols, canvasHeight / numRows);

    canvas.width = canvasWidth;
    canvas.height = canvasHeight;

    const totalWidth = squareSize * numCols;
    const totalHeight = squareSize * numRows;
    const xOffset = (canvasWidth - totalWidth) / 2;
    const yOffset = (canvasHeight - totalHeight) / 2;

    for (let i = 0; i < numRows * numCols; i++) {
    if (i >= numColors) break;
        const row = Math.floor(i / numCols);
        const col = i % numCols;
        const x = xOffset + col * squareSize;
        const y = yOffset + row * squareSize;
        ctx.fillStyle = colors[i];
        ctx.fillRect(x, y, squareSize, squareSize);
    }

    // Fill out any incomplete row with random colors from the vector
    const lastRowIndex = numRows - 1;
    const numSquaresInLastRow = numColors - lastRowIndex * numCols;
    if (numSquaresInLastRow < numCols) {
        const startIndex = numColors - numSquaresInLastRow;
        const colorsToFill = numCols - numSquaresInLastRow;
        for (let i = 0; i < colorsToFill; i++) {
            const randomColorIndex = Math.floor(Math.random() * colors.length);
            const randomColor = colors[randomColorIndex];
            const x = xOffset + (numSquaresInLastRow + i) * squareSize;
            const y = yOffset + lastRowIndex * squareSize;
            ctx.fillStyle = randomColor;
            ctx.fillRect(x, y, squareSize, squareSize);
        }
    }
}
