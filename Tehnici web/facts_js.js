var nr=0;

function change_color()
{     
let c=document.getElementsByClassName("list");

  for(let i=0;i<c.length;i++)
if(i%2==0)
	if(nr%2==0)
     c[i].style.backgroundColor="#c6c6c6";
	else
     c[i].style.backgroundColor="gray";
else
	if(nr%2==0)
	 c[i].style.backgroundColor="gray";
	else
	 c[i].style.backgroundColor="#c6c6c6";
	 
nr++;
}