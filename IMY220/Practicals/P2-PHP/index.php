<!DOCTYPE html>
<html>
<head>
	<title>IMY 220 - Prac 2</title>
	<meta charset="utf-8" />
    <!-- James Cooks u21654680 -->

</head>
<body>
	
    <form action="" method="GET">
		<label for="nCols">Number of columns: </label>
		<input type="number" id="nCols" name="numCols" />
		<input type="submit" name="" value="Apply"/>
	</form>


	
    <?php
		//Part 1
		echo "</br>";
		$filename = "names.txt";
		$names = file($filename);
		$count = 0;
		foreach($names as $name){
			$count++;
		}
		if(isset($_GET['numCols'])){
			$numCols = $_GET['numCols'];
			
			echo "<table border='black 2px solid'>";
			for($i = 0; $i < $count; $i++){
				if($i % $numCols == 0){
					echo "<tr>";
				}
				echo "<td id=" . $names[$i] .">".$names[$i]."</td>";
				if($i % $numCols == $numCols - 1){
					echo "</tr>";
				}
			}
			echo "</table>";
		}
		else{
			$numCols = 1;
			echo "<table border='black 2px solid'>";
			for($i = 0; $i < $count; $i++){
				if($i % $numCols == 0){
					echo "<tr>";
				}
				echo "<td id=" . $names[$i] .">".$names[$i]."</td>";
				if($i % $numCols == $numCols - 1){
					echo "</tr>";
				}
			}
			echo "</table>";	
		}

		//Part 2
		//Populate dropdown using names.txt
		echo "</br>";
		echo "<form action='' method='GET'>";
		echo "<select name='ingredient'>";
		foreach($names as $name){
			echo "<option value='".$name."'>".$name."</option>";
		}
		echo "</select>";
		echo "<input type='hidden' name='numCols' value='".$numCols."'/>";
		echo "<input type='submit' name='' value='Find Ingredient'/>";
		echo "</form>";

		//Bold section
		if(isset($_GET['ingredient'])){
			$ingredient = $_GET['ingredient'];
			//Style id of ingredient
			echo "<style>";
			echo "#".$ingredient."{";
			echo "font-weight: bold;";
			echo "}";
			echo "</style>";
		}



			
	?>
</body>
</html>