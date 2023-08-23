<?php
	// See all errors and warnings
	error_reporting(E_ALL);
	ini_set('error_reporting', E_ALL);

	$mysqli = mysqli_connect("localhost", "root", "", "dbuser");

	$email = isset($_POST["email"]) ? $_POST["email"] : null;
	$pass = isset($_POST["pass"]) ? $_POST["pass"] : null;

	$query = "SELECT * FROM tbusers WHERE email = '$email' AND password = '$pass'";

	$res = mysqli_query($mysqli, $query);

	$row = mysqli_fetch_array($res);

	$userid = $row["user_id"];
?>

<!DOCTYPE html>
<html>
<head>
	<title>IMY 220 - Assignment 2</title>
	<meta charset="utf-8" />
	<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.0/dist/css/bootstrap.min.css" integrity="sha384-KyZXEAg3QhqLMpG8r+8fhAXLRk2vvoC2f3B09zVXn8CA5QIVfZOJ3BCsw2P0p/We" crossorigin="anonymous">
	<link rel="stylesheet" type="text/css" href="style.css" />
	<meta charset="utf-8" />
	<meta name="author" content="James Cooks">
	<!-- Replace Name Surname with your name and surname -->
	
</head>
<body>
	<div class="container">
		<?php 
			$query = "SELECT * FROM tbusers WHERE email = '$email' AND password = '$pass' ";
			$res = $mysqli->query($query);
			if($row = mysqli_fetch_array($res))
			{
				echo 	"<table class='table table-bordered mt-3'>
							<tr>
								<td>Names</td>
								<td>" . $row['name'] . "</td>
							<tr>
							<tr>
								<td>Surname</td>
								<td>" . $row['surname'] . "</td>
							<tr>
							<tr>
								<td>Email Address</td>
								<td>" . $row['email'] . "</td>
							<tr>
							<tr>
								<td>Birthday</td>
								<td>" . $row['birthday'] . "</td>
							<tr>
						</table>";

				//Display all user's articles in reverse chronological order of date posted
				$getUserID = "SELECT user_id FROM tbusers WHERE email = '$email' AND password = '$pass'";
				$res = $mysqli->query($getUserID);
				$row = mysqli_fetch_array($res);
				$userID = $row["user_id"];

				//Get user's articles and the associated image of the article
				$getUserArticles = "SELECT * FROM tbarticles WHERE user_id = '$userID' ORDER BY date DESC";
				$res = $mysqli->query($getUserArticles);
				if (mysqli_num_rows($res) == 0){
					echo "<h1>No articles found</h1>";
				}
				else{
					echo "<h1>Latest Articles</h1>";
					echo "<div class='row articleGallery'>";
				}
				while($row = mysqli_fetch_array($res)){
					$articleID = $row["article_id"];
					$getImageName = "SELECT image_name FROM tbgallery WHERE article_id = '$articleID'";
					$res2 = $mysqli->query($getImageName);
					$row2 = mysqli_fetch_array($res2);
					$imageName = $row2["image_name"];
					//Display all articles in bootstrap cards
					//I statically set the width of my cards as the styling was not included as stated in brief
					echo "<div class='card' style='width: 18rem;'>
							<h3>". $row["date"]."</h3>
							<img class='card-img-top' src='gallery/" . $imageName . "' alt='Card image cap'>
							<div class='card-body'>
								<h5 class='card-title'>" . $row["title"] . "</h5>
								<h6 class='card-subtitle mb-2 text-muted'>- " . $row["author"] . "</h6>
								<p class='card-text'>" . $row["description"] . "</p>
						  </div>";	
						  
						  echo "</div>";
					 
				}
				


						
				echo "<h1>Create new article</h1>";
				echo 	"<form action='login.php' method='POST' enctype='multipart/form-data'>
							<div class='form-group'>
								
								<input type='hidden' class='form-control' name='email' value='" . $_POST["email"] . "' />
								<input type='hidden' class='form-control' name='pass' value='" . $_POST["pass"] . "' />
								<label for='articleName'>Article Name:</label><br>
								<input type='text' class='form-control' name='articleName' /><br>	
								<label for='articleAuthor'>Article Author:</label><br>							
								<input type='text' class='form-control' name='articleAuthor' /><br>								
								<label for='articleDescription'>Article Description:</label><br>
								<input type='text' class='form-control' name='articleDescription' /><br>

								<label for 'articleDate'>Article date:</label><br>
								<input type='date' class='form-control' name='articleDate' /><br>	

								<input type='file' class='form-control' name='picToUpload[]' id='picToUpload' multiple='multiple' /><br/> 

								<input type='submit' class='btn-standard' value='Upload article' name='submit' />
							</div>
					  	</form>";	

			}

			//Check if user has submitted an article

			if(isset($_POST["submit"])){
				//Check if any of the fields are not set
				if(empty($_POST["articleName"]) || empty($_POST["articleAuthor"]) || empty($_POST["articleDescription"]) || empty($_POST["articleDate"])){
					echo "<h2 style='color: red;'>Please fill in all fields</h2>";
					//Set focus to first empty field
					if(empty($_POST["articleName"])){
						echo "<script>document.getElementsByName('articleName')[0].focus();</script>";
					}
					else if(empty($_POST["articleAuthor"])){
						echo "<script>document.getElementsByName('articleAuthor')[0].focus();</script>";
					}
					else if(empty($_POST["articleDescription"])){
						echo "<script>document.getElementsByName('articleDescription')[0].focus();</script>";
					}
					else if(empty($_POST["articleDate"])){
						echo "<script>document.getElementsByName('articleDate')[0].focus();</script>";
					}
				}
				else{				
				//Check if uploaded file is .png and less than 2MB
				if(isset($_FILES["picToUpload"])){
					$target_dir = "gallery/";
					$uploadFile = $_FILES["picToUpload"];
					$checkSize = getimagesize($uploadFile["tmp_name"][0]);
					$uploadOk = 1;
					if($checkSize !== false){
						//Check if file is larger than 2MB
						if($uploadFile["size"][0] > 2000000){
							echo "File is too large";
							$uploadOk = 0;
						}
						else{
							$uploadOk = 1;
						}
					}
					else{
						echo "File is not an image";
						$uploadOk = 0;
					}
					$checkFileType = strtolower(pathinfo($uploadFile["name"][0], PATHINFO_EXTENSION));
					if($checkFileType != "png"){
						echo "File is not a png";
						$uploadOk = 0;
					}
					else{
						$uploadOk = 1;
					}

					//Use hash function to generate unique name for file
					$hash = hash('md5', $uploadFile["name"][0]);
					$target_file = $target_dir . $hash . "." . $checkFileType;
					$filename = $hash . "." . $checkFileType;
					
					//Upload image to /gallery
					if($uploadOk == 1){
						if(move_uploaded_file($uploadFile["tmp_name"][0], $target_file)){
							echo "The file " . basename($uploadFile["name"][0]) . " has been uploaded";
						}
						else{
							echo "Sorry, there was an error uploading your file";
						}
					}
				}
				else{
					echo "Please upload an image";
				}

				//Upload all data to database
				if($uploadOk == 1){
					$getUserId = "SELECT user_id FROM tbusers WHERE email = '$email' AND password = '$pass'";
					$res = $mysqli->query($getUserId);
					$row = mysqli_fetch_array($res);
					$userId = $row["user_id"];
					$articleName = $_POST["articleName"];
					$articleAuthor = $_POST["articleAuthor"];
					$articleDescription = $_POST["articleDescription"];
					$articleDate = $_POST["articleDate"];
					$uploadArticle = "INSERT INTO tbarticles (user_id, title, description, author, date) VALUES ('$userId', '$articleName', '$articleDescription', '$articleAuthor', '$articleDate')";
					$res = $mysqli->query($uploadArticle);
					$articleId = $mysqli->insert_id;
					$uploadImage = "INSERT INTO tbgallery (article_id, image_name) VALUES ('$articleId', '$filename')";
				}

				if($uploadOk == 1){
					if($mysqli->query($uploadImage) === TRUE){
						echo "<h2>New record created successfully</h2>";
						//Refresh page to show new article this returns an error on line 17 although pass and email are passed so just manually refresh the page
						//echo "<meta http-equiv='refresh' content='0'>";
					
					}
					else{
						echo "Error: " . $uploadImage . "<br>" . $mysqli->error;
					}
				}
			}
		
		}

		//This functionality does work but requires am manual refresh of the page to see the changes
		//Delete article
		echo "<h1>Delete article</h1>";
		echo "<form method='POST'>
				<div class='form-group'>
					<label for='articleToDelete'>Article to delete:</label><br>
					<select class='form-control' name='articleToDelete'>";
					$getUserArticles = "SELECT * FROM tbarticles WHERE user_id = '$userID' ORDER BY date DESC";
					$res = $mysqli->query($getUserArticles);
					while($row = mysqli_fetch_array($res)){
						echo "<option value='" . $row["article_id"] . "'>" . $row["title"] . "</option>";
					}
		echo 		"</select><br>
					<input type='hidden' class='form-control' name='email' value='" . $_POST["email"] . "' />
					<input type='hidden' class='form-control' name='pass' value='" . $_POST["pass"] . "' />
					<input type='submit' class='btn-standard' value='Delete article' name='delete' />
				</div>
			  </form>";

		if(isset($_POST["delete"])){
			$articleToDelete = $_POST["articleToDelete"];
			$deleteArticle = "DELETE FROM tbarticles WHERE article_id = '$articleToDelete'";
			$mysqli->query($deleteArticle);
			$deleteImage = "DELETE FROM tbgallery WHERE article_id = '$articleToDelete'";
			$mysqli->query($deleteImage);
		}



		?>
	</div>

</body>
</html>