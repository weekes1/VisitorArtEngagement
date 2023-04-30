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

const showButton = document.getElementById('btn-input');
const hiddenButtons = document.getElementById('input-div');
const image = document.getElementById('img-div');
const imagetxt = document.getElementById('imgtxt-div');


showButton.addEventListener('click', () => {
  hiddenButtons.style.display = 'block';
  showButton.style.display = 'none';
  image.style.display = 'none';
  imagetxt.style.display = 'none';

});
// Action if they push a color button 
document.getElementById('btn-red').addEventListener("click", (e) => {
	let color = document.getElementById('btn-red').innerHTML;
    addColorEntry(color);
})

document.getElementById('btn-orange').addEventListener("click", (e) => {
	let color = document.getElementById('btn-orange').innerHTML;
    addColorEntry(color);
})

document.getElementById('btn-yellow').addEventListener("click", (e) => {
	let color = document.getElementById('btn-yellow').innerHTML;
    addColorEntry(color);
})

document.getElementById('btn-green').addEventListener("click", (e) => {
	let color = document.getElementById('btn-green').innerHTML;
    addColorEntry(color);
})

document.getElementById('btn-blue').addEventListener("click", (e) => {
	let color = document.getElementById('btn-blue').innerHTML;
    addColorEntry(color);
})
document.getElementById('btn-turquoise').addEventListener("click", (e) => {
	let color = document.getElementById('btn-turquoise').innerHTML;
    addColorEntry(color);
})
document.getElementById('btn-purple').addEventListener("click", (e) => {
	let color = document.getElementById('btn-purple').innerHTML;
    addColorEntry(color);
})
document.getElementById('btn-violet').addEventListener("click", (e) => {
	let color = document.getElementById('btn-violet').innerHTML;
    addColorEntry(color);
})

// Action if complete register button
// document.getElementById('register-btn').addEventListener("click", registerUser);

// /* Set up buttons */
// document.getElementById('leave-btn').addEventListener("click", leaveSession);
// document.getElementById('send-btn').addEventListener("click", sendText);

// Watch for enter on message box
// document.getElementById('message').addEventListener("keydown", (e)=> {
//     if (e.code == "Enter") {
// 	sendText();
//     }   
// });

// document.getElementById('message').addEventListener("keydown", (e)=> {
//     if (e.code != "Enter") {
// 	TypingOn();
//     }   
// });

// Call function on page exit
//window.onbeforeunload = leaveSession;

// function completeJoin(results) {
// 	var status = results['status'];
// 	if (status != "success") {
//         if (status == "exists") alert("Username already exists!");
// 		if (status == "error") alert(results["message"]);
// 		leaveSession();
// 		return;
// 	}
// 	var user = results['user'];
// 	console.log("Join:"+user);
// 	startSession(user);
// }

function addColorEntry(color) {
	fetch(baseUrl+'/engage/add/'+color+'/'+loc, {
        method: 'get'
    })
    .then (response => response.json() )
    .catch(error => {
        {alert("Error: Something went wrong:"+error);}
    })
}

// function completeSend(results) {
// 	var status = results['status'];
// 	if (status == "success") {
// 		console.log("Send succeeded");
// 	} else {
// 		alert("Error sending message!");
// 	}
	
// }

// //function called on submit or enter on text input
// function sendText() {
//     TypingOff();
//     var message = document.getElementById('message').value;
//     console.log("Send: "+token+":"+message);
// 	fetch(baseUrl+'/chat/send/'+token+'/'+message, {
//         method: 'get'
//     })
//     .then (response => response.json() )
//     .then (data =>completeSend(data))
//     .catch(error => {
//         {alert("Error: Something went wrong:"+error);}
//     })    

// }

// function completeFetch(result) {
// 	messages = result["messages"];
// 	messages.forEach(function (m,i) {
//         console.log("in loop");
// 		name = m['user'];
// 		message = m['message'];
//         timeQueue.push(Date.now());
// 		document.getElementById('chatBox').innerHTML +=
// 	    	"<font color='red'>" + name + ": </font>" + message + "<br />";
// 	});
//     deleteOldMessages(timeQueue);
// }

// /* Check for new messaged */
// function fetchMessage() {
// 	fetch(baseUrl+'/chat/fetch/'+token, {
//         method: 'get'
//     })
//     .then (response => response.json() )
//     .then (data =>completeFetch(data))
//     .catch(error => {
//         {console.log("Server appears down");}
//     })  	
// }

// function displayUsers(response) {
//     let message = "";
//     for (var i = 0; i < response['users'].length; i++) {
//         message += " "
//         message += response['users'][i];
//     }
//     document.getElementById('members').innerHTML=message;
// }

// function fetchUsers() {
//     fetch(baseUrl+'/chat/users', {
//         method: 'get'
//     })
//     .then(response => response.json())
//     .then(data=>displayUsers(data));
//     // .catch(error => {console.log("Server Down");})
// }

// //-------------------------------------------------------------------------------
// function fetchTyping() {
//  fetch(baseUrl+'/chat/typing', {
//         method: 'get'
//     })
//  .then(response => response.json())
//  .then(data=>displayTyping(data))
//   .catch(error => {
//         {alert("Error: Something went wrong:");}
//     })    
// }


// // display the typing dots and which users are typing
// function displayTyping(response) {
//     let s = "";
//     for (var i = 0; i < response['typing'].length; i++) 
//     {
//         if (response['typing'][i] != myname)
//         {
//         s += " ";
//         s += response['typing'][i];
//         }
//     }
//     if (s.length > 0)
//     {
//         s= s.replace(/^./, "");
//         var message = s.replace(/[ ,]+/g, ",");
//         document.getElementById('typeDisplay').innerHTML="<font color='red'>" + message + ": " + "<div class='dot'></div><div class='dot'></div><div class='dot'></div>";
//     }
//     else{
//     	document.getElementById("typeDisplay").innerHTML="&#8203;";
//     }
// }

// // hit the end point to turn typing on for the user
// function TypingOn() {
// if (myname != "")
// {
// fetch(baseUrl+'/chat/typingon/'+token, {
//         method: 'get'
//     }) 
// }
// }

// // hit the end point to turn typing off for the user
// function TypingOff() {
// fetch(baseUrl+'/chat/typingoff/'+token, {
//         method: 'get'
//     }) 
// }

// //----------------------------------------------------------------------------------

// // handle the output from the register end point to either display error or hide modal if successful
// function registerError(data) {
//     console.log(data);
//     console.log(data["result"]);
//     console.log(data["result"] === "error");
//     if (data["result"] === "error") {
//         alert(data["message"]);
//     }
//     else {
//         $('#loginModal').modal('hide');
//     }
// }

// // hit register end point with data from register modal
// function registerUser(){
//     let username = document.getElementById("orangeForm-name").value;
//     let email = document.getElementById("orangeForm-email").value;
//     let password = document.getElementById("orangeForm-pass").value;
    
//     fetch(baseUrl+'/chat/register/'+username+'/'+email+'/'+password, {
//         method: 'get'
//     })
//     .then(response => response.json())
//     .then(data => registerError(data));
// }

// // if a message is over expTimeSec seconds old (from when user recieves it) remove it from the chat box
// function deleteOldMessages(timeQueue) {
//     if ((Date.now()-timeQueue[0]) > (expTimeSec*1000)) {
//         var lines = document.getElementById("chatBox").innerHTML.split("<br>");
//         lines.splice(0,1);
//         document.getElementById("chatBox").innerHTML = lines.join("<br>")
//         timeQueue.shift();
//     }
// }

// /* Functions to set up visibility of sections of the display */
// function startSession(name){
//     state="on";
    
//     document.getElementById('yourname').value = "";
//     document.getElementById('register').style.display = 'none';
//     document.getElementById('user').innerHTML = "User: " + name;
//     document.getElementById('chatinput').style.display = 'block';
//     document.getElementById('status').style.display = 'block';
//     document.getElementById('leave').style.display = 'block';
//     /* Check for messages every 500 ms */
//     inthandle=setInterval(fetchMessage,500);
//     usehandle=setInterval(fetchUsers,500);
//     typehandle=setInterval(fetchTyping,500);
// }

// function leaveSession(){
//     state="off";
//     fetch(baseUrl+'/chat/leave/'+token, {
//         method: 'get'
//     })
//     token="";
//     document.getElementById('yourname').value = "";
//     document.getElementById('register').style.display = 'block';
//     document.getElementById('user').innerHTML = "Not Logged In";
//     document.getElementById('chatinput').style.display = 'none';
//     document.getElementById('status').style.display = 'none';
//     document.getElementById('leave').style.display = 'none';
//     document.getElementById("typeDisplay").innerHTML="&#8203;";
// 	clearInterval(inthandle);
//     clearInterval(usehandle);
//     clearInterval(typehandle);
// }


