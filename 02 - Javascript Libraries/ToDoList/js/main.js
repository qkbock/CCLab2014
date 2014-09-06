//wait until the whole page has loaded and is ready before and then execute the code
$(document).ready(function() {
	//create an array to hold our list of to-do items
	var taskArray = [];
	
	//listen for a click event on the input with id addButton
	//name the Event Object data passed to the function "e" for later use
	$("#addButton").on("click", function(e){
		//prevent the default action of the click event (clearing the form and going to the URL with a ? at the end
		e.preventDefault();
		//trigger the saveTask function
		saveTask();
	});
	
	//define the saveTask function
	var saveTask = function(){
		//find the value of the text input box
		var newTask = $("#newTask").val();
		//put the text in the array
		taskArray.push(newTask);
		//send a message to the console with the array value
		console.log(taskArray);
		//set the input text to nothing
		$("#newTask").val("");	
		//trigger the displayTasks function
		displayTasks();	
	};	
	
	var displayTasks = function(){
		//find the div with the id 'taskList'  and delete all the stuff in it
		$("#taskList").empty();
		
		//go through each item in the array
		//name the information being passed to the function "i" for later use
		$(taskArray).each(function(i){
			//send a message to the console with "i" to see what it is
			//it is the loop number and the position in the array that we are currently looking at
			console.log(i);
			//create a new div HTML element
			var myNewDiv = $('<div />');
			//create a new button HTML element
			var myDeleteButton = $('<button />');
			//add an id, a class and set the inner html of the div
			$(myNewDiv).attr('id', i).addClass('task').html('<p>'+ this +'</p>');
			//add an id, inner text and an Event Listener to the button
			$(myDeleteButton).attr('id', 'deleteButton').text('X').on('click', function(e){
				//when the click event happens 
				//trigger the deleteTask function and give it the information "e" which includes all the data
				//from the click Event Object
				deleteTask(e);	
			});
			//add the button to the div
			$(myNewDiv).append(myDeleteButton);
			//add the div to the div on the webpage
			$("#taskList").append(myNewDiv);
		});
	};
	
	var deleteTask = function(e){
		//find the array number by...
		//finding the Event Object...
		//finding the "target" -- what HTML element was actually clicked
		//finding the parent element of that button -- the div
		//finding that div's id
		var theThingIWantToDelete = e.target.parentElement.id;
		//delete that item in the array
		//pick where you want to start, and how many items you want to delete
		taskArray.splice(theThingIWantToDelete, 1);
		//trigger the displayTask function to clear the page and re-display all the items in the array on the screen
		displayTasks();
	};	
});