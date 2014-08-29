// Pseudo code

// Here is the order we went about things:
// 
// Initiate and console log
// 	
// 	Know when we have pushed the button	
// 		find the button
// 		prevent default actions
//		trigger the save function
// 	
// 	Save our info
// 		find the info holder
// 		find the value in it
// 		have a place to save it
// 		save the info
// 		clear the info holder
// 		trigger the dislpay function
// 
// 	Display our list
// 		find where we want to display it
// 		make sure nothing is in it
// 		figure out how many things we need to display
// 		for each thing
// 			make a holder for the item
// 			give it an id
// 			give it a class
// 			make a holder for the text
// 			put the words in that holder
// 			put the holder in the bigger holder
// 			put the bigger holder in the screen holder
// 
// 			make a delete button
// 				make a button
// 				give it an id
// 				give it an appearance/text
// 				make it sensitive
// 					prevent default
// 					remove the whole thing (trigger the remove the whole thing function)
// 	
// 	Remove the whole thing
// 		locate the whole thing
// 		go in the array and delete the item
// 		re-display everything
		
		
		


//make a holder for the saved list items (a varible length array)
var listArray = [];

//define the saveItem function in here
var saveItem = function(){
	//locate the input field in the html
	var myNewTaskInput = document.getElementById("newTask");
	//get the value of the text typed in the input field
	var myListNewItem = myNewTaskInput.value;
	//send a message to the console to make sure it is working
	console.log(myListNewItem);
	//add the item to the array
	listArray.push(myListNewItem);
	//clear the text box by setting its "value" to nothing
	myNewTaskInput.value = "";
	//send a message to the console with the most recent task added (the last item in the array) 
	console.log(listArray[listArray.length-1]);
	//call the display Items function defined below
	displayItems();
}

var displayItems = function(){
	//send a message to the console to make sure that the function is working
	console.log("I am displaying");
	//figure out how many items we need to display by finding the length of the array
	var numberOfItems = listArray.length;
	//locate the div task list in the html
	var taskList = document.getElementById("taskList");
	//make sure it is completely empty by setting the innerHTML to nothing
	taskList.innerHTML = "";
	
	//cycle through each of the items in the array
	for(i = 0; i < numberOfItems; i++){
		//print out "i" to make sure it is working and incrementing
		console.log(i);
		//create a whole new html element of type div to hold our information
		var newTask = document.createElement("div");
		//give this new div an id - make it "i" so that we can tell which item in the array we are looking at
		newTask.id = i;
		//give the div a class name so that we can make it look pretty in css
		newTask.className = "task";
		//create a new element of type p to hold our text
		var task = document.createElement("p");
		//set the innerText (inside the <p></p> tags) to be the information stored in one spot in the array
		task.innerText = listArray[i];
		
		//where we make the delete button
		//make a new element of type button
		var button = document.createElement("button");
		//give it an id
		button.id = "deleteButton";
		//give it some inner text so that it is not just a blank button
		button.innerText = "X";
		
		//we need to know when the delete button is clicked
		//we do it here because "button" was defined within the for loop so it is in this scope
		//just like with the ADD button we add an event listener of type "click" here and pass the "event" through the function
		button.addEventListener("click", function(e){ 
			//prevent the default action
			e.preventDefault();
			//call the deleteTask function
			//in the deleteTask function we are going to need to know what was clicked, we get this information through the "click event" -- what we have called e here
			//e only exists in this scope so in order for the deleteTask function to be privy to this information we need to pass the information e into this function
			deleteTask(e);
		});
		
		//put the <p></p> inside the <div></div>
		newTask.appendChild(task);
		//put the <button> in the <div></div>
		newTask.appendChild(button);
		//put the whole <div></div> inside the <div> that already exists in the html
		taskList.appendChild(newTask);
		
	}
	//put the tasks in the taskList div
}

//define the deleteTask function in here
//we specify that this function will take in some information which we are calling theEvent
var deleteTask = function(theEvent){
	//we need to identify the entire div that we want to delete, not just the button that was clicked
	//to find our way from the click event to the div as a whole we drill down into the characteristics of the information we passed into the function
	//theEvent tells us about the whole click event that happened
	//finding the theEvent.target tells us what was actually clicked (in this case the button)
	//we want to go up one level in the document object model (DOM) to the buttons parentElement -- the div -- theEvent.target.parentElement
	//and we want to find the id of that div -- theEvent.target.parentElement.id
	//that way we know which item in the array we want to delete
	var thingWeWantToDelete = theEvent.target.parentElement.id;
	//splice cuts things
	//we tell it the array spot we want to start at
	//and how many items we want to delete
	//so we start at the thingWeWantToDelete and delete 1
	listArray.splice(thingWeWantToDelete, 1);
	//now that the item is removed from the array we can just run our displayItems function again and it will clear the holder div and re-display the updated list
	displayItems();
}

//define the startThisThing function in here
var startThisThing = function(){
	//make sure it is working by sending a message to the console
	console.log("HELLO, WORLD");
	//identify the button in the html
	var addButton = document.getElementById("addButton");
	//listen for the button click
	addButton.addEventListener("click", function(e){
		//dont let it do its usual thing cause thats not what we want
		e.preventDefault();
		//make sure this is working by sending a message to the console
		console.log("I'VE BEEN PUSHED");
		//call the saveItem function defined above	
		saveItem();
	});
}

//tell the browser to execute this code as soon as the window loads
window.onload = startThisThing();