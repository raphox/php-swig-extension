<?php

include("MyModule.php");

$teste = new Hello();

echo '<pre><code>';
var_dump(get_class_methods($teste));
echo '</code></pre>';

$teste->setFormal(true);

echo $teste->greeting();
