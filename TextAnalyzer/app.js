function findAverage(tokens)
{
    // Join all the tokens together
    var bigWord = tokens.join("");

    return (bigWord.length / tokens.length).toFixed(2);
}

function findDistinctWords(tokens)
{
    var words = [];

    // Go through the tokens array, and have another array to keep track of the distinct words
    for(var i = 0; i < tokens.length; i++)
    {
        // If the token is not in the array, add it
        if(words.indexOf(tokens[i]) === -1)
        {
            words.push(tokens[i]);
        }
    }

    return words.length;
}

function tokenize(text)
{
    // Gets ride of any newlines (workds for windows, linux and OSX)
    var text1 = text.replace(/(\r\n\t|\n|\r\t)/gm, " ");

    // Gets rid of any spaces, tabs
    var newText = text1.replace(/\s\s+/g, ' ');

    // Get rid of any punctuation
    newText = newText.replace(/[.,\/#!$%\^&\*;:{}=\-_`~()]/g, "");

    // Creates an array of all the tokens and returns it
    newArray = newText.split(" ");
    return newArray;
}

function setSummary(text)
{
    // Get all the values
    var tokens = tokenize(text);
    var numDwords = findDistinctWords(tokens);
    var avLength = findAverage(tokens);

    // Show it on the html
    var report = $('.report');
    report.find('.js-count').text(tokens.length)
    report.find('.js-ucount').text(numDwords);
    report.find('.js-avLength').text(avLength + " characters");

    report.removeClass('hidden');

}

function handleSubmit()
{
    $('#textAnalyze').submit(function(event) {
        event.preventDefault();

        // Empty the summary if there is contents
        $('js-count').empty();
        $('js-ucount').empty();
        $('js-avlength').empty();

        // Get the input
        var input = $(this).find('textarea[name="inputText"]').val();

        setSummary(input);
    });
}

$(function() {
    handleSubmit();
});