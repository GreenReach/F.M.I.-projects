window.onload=func;
var a,b,c,d;
let p1,p2,p3,p4;
var ok=0;
var n,i=0;
var ok1=0;
var puncte = []
let m;
let v = [];
var ok2=0;
var oky=0




function func()
{


var canvas = document.createElement("canvas");
canvas.setAttribute("width",1100);
canvas.setAttribute("height",1100);
canvas.setAttribute("style", "position: absolute; x:700; y:700;");
document.body.appendChild(canvas);


var context = canvas.getContext("2d");

document.getElementById('file').onchange = function(){

  var file = this.files[0];

  var reader = new FileReader();
  reader.onload = function(progressEvent){
    
	 var puncte = [];
	 var convex= []
    var lines = this.result.split(' ');
	
    for(var line = 0; line < lines.length; line++)
	{
		p1=parseInt(lines[n]);
		p1=parseInt(lines[n+1]);
		p2=parseInt(lines[lines.length-2]);
		p2=parseInt(lines[lines.length-1]);
			if(line==0)
		{
		n=parseInt(lines[line]);
		}
			else 
		{		
			if(ok==0)
			{
				a=parseInt(lines[line]);
				ok=1;
			}	
			else if(ok==1)
			{ 
				ok=0;
				b=parseInt(lines[line]);
				
				if(i<n)
				{
					context.fillRect((a+10)*50-5,(b+10)*50-5,10,10);
					i++;
				}
				else
				{    
			 
					if(oky==0)
					{
					p1=a;
					p2=b;
					oky=1;
					}
					
					v.push(a);
					v.push(b);
					c=parseInt(lines[line+1]);
					
					d=parseInt(lines[line+2]);
					p3=parseInt(lines[lines.length-3]);
					p4=parseInt(lines[lines.length-2]);
					
						context.beginPath();
						context.strokeStyle="red";
						context.moveTo((a+10)*50,(b+10)*50);
						context.lineTo((c+10)*50,(d+10)*50);
						context.stroke();
						context.fillStyle="red";
						context.fillRect((a+10)*50-5,(b+10)*50-5,10,10);
						context.fillRect((c+10)*50-5,(d+10)*50-5,10,10);
					
					
				
				}
			
			}
			
		 console.log(v);
		 context.beginPath();
						context.strokeStyle="red";
						context.moveTo((p1+10)*50,(p2+10)*50);
						context.lineTo((p3+10)*50,(p4+10)*50);
						context.stroke();
context.fillRect((p1+10)*50-5,(p2+10)*50-5,10,10);
context.fillRect((p3+10)*50-5,(p4+10)*50-5,10,10);
		}
	}
  };
  reader.readAsText(file);
};
}