build project:
	go to build folder
	type (cmake ..)
	type (cmake --build . --config Release)
	
git initialize:
	git config --global user.name "DaniilBukov"
	git config --global user.email "bukovda@gmail.com"
	git init
	git remote add origin https://github.com/DaniilBukov/OpenGL-EDU.git"
	git branch -M master
	
git commit:
	git add .
	git commit -m "message"
	git push -u origin master
	
git pull:
	git fetch origin
	git merge origin/master
	git pull
	
update glfw:
	git subtree pull --prefix=external/glfw glfw master --squash