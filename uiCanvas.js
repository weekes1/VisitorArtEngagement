const canvas = document.getElementById("myCanvas");
const ctx = canvas.getContext("2d");

// Define the properties of the squares
const squareWidth = 100;
const squareHeight = 100;
const squareSpacing = 10;
const squareCount = 8;
const totalWidth = (squareWidth + squareSpacing) * (squareCount - 1) + squareWidth;
const startingX = (canvas.width - totalWidth) / 2 - squareWidth/2 + 50;
const startingY = (canvas.height - squareHeight) / 2;

// Define an array of colors and their names
const colors = [
  { name: "Passion", code: "#ff0000" },
  { name: "Joy", code: "#ffa500" },
  { name: "Happy", code: "#ffff00" },
  { name: "Peace", code: "#32CD32" },
  { name: "Hope", code: "#40E0D0" },
  { name: "Sadness", code: "Blue" },
  { name: "Reflective", code: "purple" },
  { name: "Power", code: "violet" }
];

// Draw the squares
for (let i = 0; i < squareCount; i++) {
  const x = startingX + i * (squareWidth + squareSpacing);
  const y = startingY;
  
  // Fill the square with a different color
  const color = colors[i];
  ctx.fillStyle = color.code;
  ctx.fillRect(x, y, squareWidth, squareHeight);
  
  // Add text to the square
  if(color.name == "Happy"){
    ctx.fillStyle = "Black";
  ctx.font = "20px Arial";
  ctx.textAlign = "center";
  ctx.textBaseline = "middle";
  ctx.fillText(color.name, x + squareWidth/2, y + squareHeight/2 + 6);
  }
  else{
    ctx.fillStyle = "White";
    ctx.font = "20px Arial";
    ctx.textAlign = "center";
    ctx.textBaseline = "middle";
    ctx.fillText(color.name, x + squareWidth/2, y + squareHeight/2 + 6);
  }
}