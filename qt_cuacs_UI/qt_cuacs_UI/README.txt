cuACS (D4)

Team: 4our People

@authors
Kaleb Tesfay    | 101048170
Adam Farah      | 100966918
Japinder Sandhu | 101021899
Samson Teklay   | 100972872

Professor. Christine Laurendeau

A message from author's:
Coded with ❤️

Purpose of Deliverable:
  - The purpose of this Deliverable is to implement the following features:
    - Full Implementation of acs algorithm for matching clients and animals

List of Source/Header/Data File:
  - This folder contains 25 files (not counting the README) and 1 Folder
    - Task: Programming Implementations
      - 1 Folder
        - database
          - database.db
            - Database file for the project.
      - 1 .pro file.
        - qt_cuacs_UI.pro
          - QT implemented file that is in charge of setting up startup options.
      - 1 .pro.user file.
        - qt_cuacs_UI.pro.user
          - QT implemented file.
      - 1 .ui file.
        - mainwindow.ui
          - In charge of Client-side/Front-end.
      - 8 .cpp files.
        - Animal.cpp
          - Getter and Setter Methods for Animal objects.
        - Client.cpp
          - Getter and Setter Methods for Client objects.
        - Control.cpp
          - Implemented this class to create the Database file.
        - login.cpp
          - Connects the Database to the application.
        - Shelter.cpp
          - Bridges the program so it can store added animals.
        - View.cpp
          - Prints the stored animals for debugging reasons.
        - main.cpp
          - main() class for the program.
        - mainwindow.cpp
          - In charge of Server-side/Back-end calling so buttons can operate with other classes.
        -ACM.cpp
          -In charge of calculating attributes in matching.
      - 7 .h files.
        - Animal.h
          - Header file for Animal class.
        - Client.h
          - Header file for Client class.
        - AnimalList.h
          - Template class for storing Animals in a Linked List.
        - Control.h
          - Header file for Control class.
        - login.h
          - Header file for login class.
        - Shelter.h
          - Header file for Shelter class.
        - View.h
          - Header file for View class.
        - mainwindow.h
          - Header file for for mainwindow class.
        -ACM.h
          - Header file for animal shelter matching class
      - 1 makefile
        - Makefile
          - Typing make in cmd line...
            - This compiles all the programs at once.
              - Compiles all the programs and creates their appropriate object files.
                - Combines all object files to one.
                  - Creates qt_cuacs_UI object file.

Compilation Cmd:
  - To compile, you'll need to access the respected directory all the files are located in via Terminal.
    - Make sure you are using the Vitural Machine's Linux Operating System.
      - Once you are in the respected directory, you'll need to do the following.
        - untar the file
          - tar -xvf cuACS.tar
	   - The folder name is called qt_cuacs_UI
	    - cd into qt_cuacs_UI
             - cd qt_cuacs_UI
        - Run the script
          - sh cuacs


Lanching and Operating Instructions:
  - Once the code is ran...
    - A UI representation of our application will pop up.
      - There will be two options the user will be able to do.
        - Click Client
          - Click View Animals
           - Displays all the Animals in the database.
	  - Click Edit Client
           - Displayes the IDs of all Clients, select 1.
	    - Detailed information will be showed and user can edit it.
          - Click Back
            - Redirects you to the previous page.
        - Click Staff
          - Directs the user to a Page that has a View Animals, View Clients, Add Animal, Add Client, Back button.
            - Click View Animals
              - Directs user to a page that showcases all animals in the database.
                - Click Back
                  - Directs user back to Staff page.
                - Click Homepage
                  - Directs user back to Homepage.
            - Click View Clients
             - Directs user to a page that showcases all clients in the database.
              - Click Back
                - Directs user back to Staff page.
              - Click Homepage
                - Directs user back to Homepage.
            - Click Add Animal
              - Directs user a page where the user can add animals to the database.
                - Click Save
                  - Adds the animal inputted to the database.
                - Click List Attributes
                 - Details the specific Animal's information.
                - Click Clear
                 - Clears the information in the text boxes.
                - Click Back
                  - Directs user back to Staff page.
                - Click Homepage
                  - Directs user back to Homepage.
            - Click Add Client
              - Directs user a page where the user can add clients to the database.
                - Click Save
                  - Adds the client inputted to the database.
                - Click List Attributes
                  - Details the specific Client's information.
                - Click Clear
                  - Clears the information in the text boxes.
                - Click Back
                  - Directs user back to Staff page.
                - Click Homepage
                  - Directs user back to Homepage.
              - Click Back
               - Redirects users to previous page.
               - Click ACM
                - Click Start
                    -From the list presented click Id of clients to get corisponding animal match
