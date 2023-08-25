class FactorialChecker
{
	printFactorial = (num) =>
	{
		let fact = 1;
		for (let i = 1; i <= num; i++) 
		{
			fact *= i;
		}
		return `The factorial of ${num} is ${fact}`;

	}//end function

	fillArray = (num) =>
	{
		const start = num;
		let init = 1; 
		let i = 1; 
		const arr = []; 
		let fac = true; 
		while (true){
			init = init*i; 
		  	if (init%2==0 || init==1){        
				if(init>start){
				  	fac=false;
					break;
			  	}
			arr.push(i);
			i++; 
			if(init==start)
				break; 
		  }
		}
		if (fac) return `The values that make up the factorial ${num}: ${arr}`
		else return "This is not a factorial";
	}//end function

}//end FactorialChecer


function PigLatinEncrypt(str)
{
	const vowels = "aeiou";
	const vowelsArr = vowels.split("");
	const newStr = [];
	str = str.toLowerCase();

    if (vowelsArr.includes(str[0])) {
        newStr.push(str + "way");
    } else {
        const firstMatch = str.match(/[aeiou]/g) || 0;
        const firstVowel = str.indexOf(firstMatch[0]);
        newStr.push(str.substring(firstVowel) + str.substring(0, firstVowel) + "ay");
    }

	return `The result when converting ${str} to Pig Latin is ${newStr}`;



}//end PigLatinEncrypt

const checkUniqueLetters =  (input) => {
	//Convert string to array of letters
	const uniqueCount = input.split('').reduce((count, letter) => {
		//If letter is not in the array, add it
		if (!count.includes(letter)) {
			count.push(letter);
		}
		return count;
	}, []).length;

	return `The word ${input} has ${uniqueCount} unique letters`;
}


const checker = new FactorialChecker();

document.getElementById("GenerateFactorial").onclick = function()
{
	document.getElementById("FactorialResult").innerHTML = checker.printFactorial(document.getElementById("FactorialValue").value);
}

document.getElementById("GenerateFactorialList").onclick = function()
{
	document.getElementById("FactorialListResult").innerHTML = checker.fillArray(document.getElementById("FactorialInput").value);
}

document.getElementById("PigLatinEncrypt").onclick = function()
{
	document.getElementById("PigLatinResult").innerHTML = PigLatinEncrypt(document.getElementById("SentenceToConvert").value);
}

document.getElementById("checkRecurringChars").onclick = function()
{
	document.getElementById("recurringCharsResult").innerHTML = checkUniqueLetters(document.getElementById("charChecker").value);
}