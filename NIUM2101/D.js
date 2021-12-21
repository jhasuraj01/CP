'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n');    
    main();    
});

function readLine(){
    return inputString[currentLine++];
}

function solution(){
    let h;
    const N = Number(readLine());

    let C = {};
    
    const H = readLine().split(" ").map(Number);

    let size = 0;

    for (let i = 0; i < N; ++i)
    {
        h = H[i];
        if(C[h]) {
            C[h] += 1;
        }
        else {
            C[h] = 1;
            size++;
        }
        
    }

    if (size > 12)
    {
        console.log("no\n")
        return;
    }
    
    if (size == 12)
    {
        console.log("yes")
        return;
    }
    
    let diff = 12 - size;

    for (let i in C)
    {
        diff -= C[i] - 1;
    }

    if (diff > 0)
    {
        console.log("no")
    }
    else
    {
        console.log("yes")
    }
}

function main(){
    // input in nodeJs
	let test = parseInt(readLine(),10);
	while(test--){
		solution();
	}
}