program proc1 (input, output); 
  var x, y: integer;      
  procedure p;             
     var z:integer;        
     procedure q;
       var a: integer;
			 procedure r;
					var b: integer;
					begin
					end;
       begin
       end;      
     begin                   
       z:=x;                   
       x:=x-1;           
       if (z>1)                   
         then p 
         else y:=1; 
       y:=y*z      
     end;
begin                     
   read(x);            
   p;  
   write (x,y)             
end.
