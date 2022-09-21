<html>
<body>
<form action="welcome.php" method="post">
Name: <input type="text" name="name"><br>
<input type="radio" name="gender" value="female">Female
<input type="radio" name="gender" value="male">Male
<input type="radio" name="gender" value="other">Other
E-mail: <input type="text" name="email">
Website: <input type="text" name="website">
Comment: <textarea name="comment" rows="5" cols="40"></textarea>

<input type="submit">
</form>
</body>

</html>
<html>
<body>
 Welcome <?php echo $_POST["name"]; ?><br>
Your email address is: <?php echo $_POST["email"]; ?>
 </body>
</html>