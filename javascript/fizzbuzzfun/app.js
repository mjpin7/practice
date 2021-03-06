/**
 * Function to return the correct fizzbuzz value
 * 
 * @param {number} num          The number to get the value for
 */
function whatVal(num)
{
    var value = num;

    if(num % 15 == 0)
    {
        value = "fizzbuzz";
    }
    else if(num % 5 == 0)
    {
        value = "buzz";
    }
    else if(num % 3 == 0)
    {
        value = "fizz";
    }

    return value
}

/**
 * Function to make the fizzbuzz array
 * 
 * @param {number} num 
 */
function makeArray(num)
{
    var array = [];

    for(var i = 1; i <= num; i++)
    {
        array.push(whatVal(i));
    }

    return array;
}

/**
 * Function to put the fizzbuzz boxes on the screen
 * 
 * @param {number} num 
 */
function doFizz(num)
{
    // Make the array
    var myArray = makeArray(num);

    // Go through the array
    myArray.forEach(function(item) {
        // Create the html
        var html = $('<div class="fizzbuzz-item"><span>' + item + '</span></div>');

        // Add the necessary class
        if(item === "fizz" || item === "buzz" || item === "fizzbuzz")
            html.addClass(item);

        // Add the html to the end of the area
        $('.results').append(html);
    });
}

/**
 * Function to handle the form
 */
function formHandle()
{
    $('#chooseANumber').submit(function(event) {
        // Prevent it from posting
        event.preventDefault();

        // If there is previous data, erase it
        $('.results').empty();

        // Get the value inputted
        var input = parseInt( $(this).find('input[name="choice"]').val());
        doFizz(input);
    })
}

// Call the function on page load
$(function() {
    formHandle()
});