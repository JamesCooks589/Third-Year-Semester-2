function FactorialChecker(){
    this.printFactorial = function(n){
        if (n < 0){
            return "Invalid input";
        }
        else if (n === 0 || n === 1){
            return 1;
        }
        else{
            return n * this.printFactorial(n - 1);
        }
    };

    //Takes in a number and does reverse of factorial if n is a valid factorial
    this.fillArray = function(factorialResult) {
        // Helper function to calculate factorial
        function calculateFactorial(n) {
          if (n === 0 || n === 1) {
            return 1;
          } else {
            return n * calculateFactorial(n - 1);
          }
        }
      
        // Check if the given number is a factorial
        let i = 1;
        while (calculateFactorial(i) < factorialResult) {
          i++;
        }
      
        if (calculateFactorial(i) !== factorialResult) {
          return "This is not a factorial";
        }
      
        // Fill the array with numbers that make up the factorial
        const resultArray = [];
        while (i > 0) {
          resultArray.unshift(i);
          i--;
        }
      
        return resultArray;
      }

}

const factorialChecker = new FactorialChecker();

//Event listeners
document.getElementById("GenerateFactorial").addEventListener("click", function(){
    const input = parseInt(document.getElementById("FactorialValue").value);
    const output = factorialChecker.printFactorial(input);
    document.getElementById("FactorialResult").innerHTML = output;
});

document.getElementById("GenerateFactorialList").addEventListener("click", function(){
    const input = parseInt(document.getElementById("FactorialInput").value);
    const output = factorialChecker.fillArray(input);
    document.getElementById("FactorialListResult").innerHTML = output;
});

//Task 2
function pigLatinEncrypt(word){
    word = word.toLowerCase();
    const vowels = ["a", "e", "i", "o", "u"];
    let firstLetter = word.charAt(0);
    let result = "";
    //Check if word contains a vowel
    var WordContainsVowel = false;
    for (let i = 0; i < vowels.length; i++){
        if (word.includes(vowels[i])){
            WordContainsVowel = true;
        }
    }


    if (WordContainsVowel){
        if (vowels.includes(firstLetter)){
            result = word + "way";
        }
        else{
            let vowelIndex = 0;
            for (let char of word){
                if (vowels.includes(char)){
                    vowelIndex = word.indexOf(char);
                    break;
                }
            }
            result = word.substring(vowelIndex) + word.substring(0, vowelIndex) + "ay";
        }
    }
    else{
        result = word + "ay";
    }
    return result;
}

document.getElementById("PigLatinEncrypt").addEventListener("click", function(){
    const input = document.getElementById("SentenceToConvert").value;
    //Work for sentence not just word
    const output = input.split(" ").map(pigLatinEncrypt).join(" ");
    document.getElementById("PigLatinResult").innerHTML = output;
});