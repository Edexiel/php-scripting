<?php

# example.php

echo("Hello World\n");
$mod = sin(microtime(true));
$amplitude = 100;
$offset = 400;
$posx = ($mod*$amplitude)+$offset;
draw_text('Hello',(int)$posx,100,50);
print_coucou();


?>
