// Rest based chat client
// Jim Skon 2022
// Kenyon College

var baseUrl = 'http://3.87.226.20:5010';
var state="off";
var loc="JS-Test";
var expTimeSec = 10; // number of seconds that a message stays before expiring

/* Start with text input and status hidden */
// document.getElementById('chatinput').style.display = 'none';
// document.getElementById('status').style.display = 'none';
// document.getElementById('leave').style.display = 'none';

const colorButton = document.getElementById('btn-input');
const inputButtons = document.getElementById('input-div');
const image = document.getElementById('img-div');
const imagetxt = document.getElementById('imgtxt-div');
//const goal = document.getElementById('goal-txt'); 
const thank = document.getElementById('Thank-div');
const pls = document.getElementById('pls-div');  
const canv = document.getElementById('myCanvas'); 
const piece = document.getElementById('piece-choose-div'); 
const piecebtn = document.getElementById('choose-piece-btn'); 
const videoButton = document.getElementById('btn-video');
const visitingButton = document.getElementById('btn-visiting');
const kenyonButton = document.getElementById('btn-kenyon');
 
// Actions for when the location buttons are pressed: shows color inputs and sets location variable
videoButton.addEventListener('click', () => {
    showColorInputs();
    loc="Video";
});

visitingButton.addEventListener('click', () => {
    showColorInputs();
    loc="Visit";
});
kenyonButton.addEventListener('click', () => {
    showColorInputs();
    loc="Kenyon";
});



// Action if they push a color button: adds the color, displays thanks, waits 2.5s resets page
const colorWheel = document.getElementById("color-wheel");
colorWheel.addEventListener("click", function(event) {
	var colorSlice = event.target.closest(".color-slice");
	if (colorSlice) {
	var colorId = colorSlice.getAttribute("id").substring(6); 
	console.log(colorId);
	addColorEntry(colorId);
    	displayThanks();
    	setTimeout(refreshInputs, 2500)
}
});


// hits the add color and location end point with user input color and location
function addColorEntry(color) {
	fetch(baseUrl+'/engage/add/'+color+'/'+loc, {
        method: 'get'
    })
    .then (response => response.json() )
    .catch(error => {
        {alert("Error: Something went wrong:"+error);}
    })
}

// hides the location inputs and shows the color inputs
function showColorInputs() {
    inputButtons.style.display = 'block';
    image.style.display = 'none';
    imagetxt.style.display = 'none';
  //  goal.style.display = 'none';
    piecebtn.style.display = 'none';
    piece.style.display = 'none';
    pls.style.display = 'block';
}

// hides all inputs and shows a thank you message to the user
function displayThanks() {
    inputButtons.style.display = 'none';
    pls.style.display = 'none';
    canv.style.display = 'none';
    thank.style.display = 'block';
}

// resets the appearance of the page to how it originally is
function refreshInputs() {
    thank.style.display = 'none';
//    goal.style.display = 'block';
    canv.style.display = 'block';
    image.style.display = 'block';
    imagetxt.style.display = 'block';
    piece.style.display = 'block';
    piecebtn.style.display = 'block';
}
