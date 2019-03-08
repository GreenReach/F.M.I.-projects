window.onload=pictures
let pic;
let win;
let L="";
let inter;
let art=document.getElementById("last");
let col1=document.getElementById("color1");
let col2=document.getElementById("color2");
let all_koala=document.getElementsByClassName("make_koala");
let Koala=["koala","koala","koala","koala","koala","koala"];
	
	let coord=document.getElementById("page");
	
function b1()
{
	pic.nr=1;
	//alert(Koala[pic.nr]);
	pic.src=Koala[pic.nr];
}
function b2()
{
    pic.nr=2;
	pic.src=Koala[pic.nr];
}
function b3()
{
	pic.nr=3
	pic.src=Koala[pic.nr];
}
function b4()
{
	pic.nr=4;
	pic.src=Koala[pic.nr];
}
function b5()
{
	pic.nr=5;
	pic.src=Koala[pic.nr];
}
function b6()
{
	pic.nr=Math.floor(Math.random()*5)+1;
	pic.src=Koala[pic.nr];
}


function showCoords(event) {
 
}


function deschide()
{
	if(pic.nr==1)
		win=window.open("https://ro.wikipedia.org/wiki/Koala");
	if(pic.nr==2)
		win=window.open("https://www.nationalgeographic.com/animals/mammals/k/koala/");
	if(pic.nr==3)
		win=window.open("https://www.britannica.com/animal/koala");
	if(pic.nr==4)
		win=window.open("https://www.australiazoo.com.au/our-animals/mammals/koalas");
	if(pic.nr==5)
		win=window.open("https://www.savethekoala.com/");
}

function inchide()
{
	win.window.close();
}


function koali()
{
	let koala_write=document.getElementsByTagName("span")
	for(i in koala_write)
	{
		koala_write[i].className="write";
       koala_write[i].classList.add("addi");
	   koala_write[i].innerHTML="koala";
	   
	}
}

function start()
{let x=1;
	inter=setInterval(function()
	{
		pic.src="koala" + x +".jpg";
		x++;
		if(x==6)
			x=1;
		
		
	},1000,x);
}

function stop()
{
	clearInterval(inter);
}

function change1()
{
	event.preventDefault();
	alert("daa");
}

function dragstart(ev)
{
	//alert("dragstart");
}

function drag(ev)
{
all_koala[0].style.color="red";
all_koala[1].style.color="red";
}

function drag1(ev)
{
all_koala[0].style.color="blue";
all_koala[1].style.color="blue";
}

function drop(ev)
{
	alert("drop");
}


function change_col()
{
	alert("You have pressed me, a new koala may appear");

}

function pictures()
{ 
	let place=document.getElementById("picture");
	let exit=document.getElementById("exit");
	let info=document.getElementById("info");
	let more_info=document.getElementById("more_info");
	let article=document.getElementById("parinte");
	let koalify=document.getElementById("koalify");
	let start_int=document.getElementById("7");
	stop_int=document.getElementById("8");
	pic = document.createElement("img");
	pic.nr=0;
	place.appendChild(pic)
	let r1=document.getElementById("1");
	let r2=document.getElementById("2");
	let r3=document.getElementById("3");
	let r4=document.getElementById("4");
	let r5=document.getElementById("5");
	let r6=document.getElementById("6");
	
	for(i=0;i<Koala.length;i++)
		Koala[i]+=i+".jpg";
	
	r1.addEventListener("click",b1,true);
	r2.addEventListener("click",b2,true);
	r3.addEventListener("click",b3,true);
	r4.addEventListener("click",b4,true);
	r5.addEventListener("click",b5,true);
	r6.addEventListener("click",b6,true);
	
	let diiiv=document.getElementById("diiiv");
	diiiv.addEventListener("click",change_col,true);
	
	
	pic.onclick=deschide;
	exit.onclick=inchide;
	
	info.onclick=function()
		{   if(pic.nr==0)
			this.preventDefault();
			let n=getComputedStyle(pic);
			let m="Width: "+ n.getPropertyValue("width") + " Height: " + n.getPropertyValue("height");  
			let m1=m.toUpperCase();
			alert(m1);
			let d=new Date;
			this.value="Picture Info(last shown picture " + pic.nr +" info on "+ d+")";
		}
		
		
	article.nr=0;	
	article.onclick=function(){this.nr++; localStorage.clickcount++;};
	
	more_info.onclick=function(){
		 event.stopPropagation();
		var x=this.parentElement.nodeName;
		var y=document.getElementsByName(x);
		alert("clicks in the current area: " +y[0].nr + " Total clicks: " + localStorage.clickcount);
		
	}
	
	koalify.onclick=koali;	
	start_int.onclick=start;
	stop_int.onclick=stop;
	
	
	let name=document.getElementById("name");
	name.onkeydown=function(event)
	{
		if(pic.nr==0)
			event.preventDefault();
		else
		{
	   let a=event.key
	   if(a =="Enter")
	   {alert("You have named this koala: " +L);L="";}
	   else
		L+=a;
		}
	}
Koala.sort();	
let base=document.getElementById("base")
base.onclick=function(){
	if(event.target.id=="title")
	{var x = event.pageX;
	var y = event.pageY;

	if(x>=100 && y>125)
	alert(  "You have pressed the koala");
	}
}
}