# Year_3Game
Work for games engineering module

Each lab is in a new branch to set the labs up you have to:

1. create new directory e.g. Lab2
2. go to new directory and create new branch: $ git checkout -b Lab2
3. then add the submodule files to the new branch:  git submodule update --init --recursive
4. edit the CMakeCache.txt file in C:\Year3\Lab{number}\Year_3Game\out\build\x64-Debug to add the correct folder path. Do find/replace e.g
	find: e.g. C:\Year3\Lab2
	replace to: e.g. C:\Year3\Lab3
5. then open the new folder in visual studio and it should build the new lab project.
