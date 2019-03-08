var nr=1


function make()
{
	 let sect = document.getElementById("sect");
	 let x = document.createElement("IMG");
     x.src="koala" + nr + ".jpg";
	 x.style.width="25%";
	 x.onclick= function(){sect.removeChild(x);}
	 sect.appendChild(x);
	 
	 nr++;
	 if(nr==7)
		 nr=1;
}
