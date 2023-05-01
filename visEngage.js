// Rest based chat client
// Jim Skon 2022
// Kenyon College

var baseUrl = 'http://18.223.238.7:5010';
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
const goal = document.getElementById('goal-txt'); 
const thank = document.getElementById('Thank-div');
const pls = document.getElementById('pls-div');  
const canv = document.getElementById('myCanvas'); 
const welc = document.getElementById('welcome-div'); 
const piece = document.getElementById('piece-choose-div'); 
const piecebtn = document.getElementById('choose-piece-btn'); 
const videoButton = document.getElementById('btn-video');
const visitingButton = document.getElementById('btn-visiting');
const kenyonButton = document.getElementById('btn-kenyon');
 

videoButton.addEventListener('click', () => {
  colorButton.style.display = 'block';
  image.style.display = 'none';
  imagetxt.style.display = 'none';
  goal.style.display = 'none';
  piecebtn.style.display = 'none';
 piece.style.display = 'none';
 pls.style.display = 'block';
 colorButton.style.display = 'block';
 loc="Video";
});

visitingButton.addEventListener('click', () => {
  colorButton.style.display = 'block';
  image.style.display = 'none';
  imagetxt.style.display = 'none';
  goal.style.display = 'none';
  piecebtn.style.display = 'none';
 piece.style.display = 'none';
 pls.style.display = 'block';
 colorButton.style.display = 'block';
 loc="Visiting";
});
kenyonButton.addEventListener('click', () => {
  colorButton.style.display = 'block';
  image.style.display = 'none';
  imagetxt.style.display = 'none';
  goal.style.display = 'none';
  piecebtn.style.display = 'none';
 piece.style.display = 'none';
 pls.style.display = 'block';
 colorButton.style.display = 'block';
 loc="Kenyon";
});

colorButton.addEventListener('click', () => {
  inputButtons.style.display = 'block';
  colorButton.style.display = 'none';
  image.style.display = 'none';
  imagetxt.style.display = 'none';
  goal.style.display = 'none';
  canv.style.display = 'none';
});

// Action if they push a color button 
document.getElementById('btn-red').addEventListener("click", (e) => {
	let color = "red";
    addColorEntry(color);
     colorButtons.style.display = 'none';
     pls.style.display = 'none';
     canv.style.display = 'none';
     welc.style.display = 'none';
     thank.style.display = 'block';
    })

document.getElementById('btn-orange').addEventListener("click", (e) => {
	let color = "orange";
    addColorEntry(color);
     colorButtons.style.display = 'none';
     pls.style.display = 'none';
     thank.style.display = 'block';
     canv.style.display = 'none';
     welc.style.display = 'none';
})

document.getElementById('btn-yellow').addEventListener("click", (e) => {
	let color = "#ffff00";
    addColorEntry(color);
     colorButtons.style.display = 'none';
     pls.style.display = 'none';
     thank.style.display = 'block';
     canv.style.display = 'none';
     welc.style.display = 'none';
})

document.getElementById('btn-green').addEventListener("click", (e) => {
	let color = "#32CD32";
    addColorEntry(color);
     colorButtons.style.display = 'none';
     pls.style.display = 'none';
     thank.style.display = 'block';
     canv.style.display = 'none';
     welc.style.display = 'none';
})

document.getElementById('btn-blue').addEventListener("click", (e) => {
	let color ="blue";
    addColorEntry(color);
     colorButtons.style.display = 'none';
     pls.style.display = 'none';
     thank.style.display = 'block';
     canv.style.display = 'none';
     welc.style.display = 'none';
})

document.getElementById('btn-turquoise').addEventListener("click", (e) => {
	let color = "#40E0D0";
    addColorEntry(color);
     colorButtons.style.display = 'none';
     pls.style.display = 'none';
     thank.style.display = 'block';
     canv.style.display = 'none';
     welc.style.display = 'none';
})

document.getElementById('btn-purple').addEventListener("click", (e) => {
	let color = "purple";
    addColorEntry(color);
     colorButtons.style.display = 'none';
     pls.style.display = 'none';
     thank.style.display = 'block';
     canv.style.display = 'none';
     welc.style.display = 'none';
})

document.getElementById('btn-violet').addEventListener("click", (e) => {
	let color = "violet";
    addColorEntry(color);
     colorButtons.style.display = 'none';
     pls.style.display = 'none';
     thank.style.display = 'block';
     canv.style.display = 'none';
     welc.style.display = 'none';
})

function addColorEntry(color) {
	fetch(baseUrl+'/engage/add/'+color+'/'+loc, {
        method: 'get'
    })
    .then (response => response.json() )
    .catch(error => {
        {alert("Error: Something went wrong:"+error);}
    })
}
