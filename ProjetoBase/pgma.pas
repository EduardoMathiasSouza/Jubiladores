program exemplo74 (input, output);
var z, x: integer;
   procedure g(t, u:integer);
   var y, a : integer;
   begin
      y:=t*t; z:=z+x+y;
      write(z)
   end;

   procedure h (y : integer);
   var x : integer;
      procedure f(y, v : integer);
      var t, b : integer;
      begin
         t:=z+x+y; 
				 g(t, 1);
         z:=t
      end;
   begin
      x:=y+1;
      f(x, 1);
      g(z+x, 0)
   end;
begin
   z:=1;
   x:=3;
   h(x);
   g(x, 0);
   write(x,z)
end.
   

