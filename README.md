<div align=center>
     <h1>2D Graphics Modeler</h1>
</div>

## Contributors

| Member            | Roles         |
| ----------------- | ------------- |
| Connor Darling    | Product Owner |
| Carlos Aguilera   | SCRUM Master  |
| Cameron Rosenthal | Team Member   |
| Liam Eastwood     | Team Member   |
| Joesph Bobby      | Team Member   |

<br/>

### IMPORTANT

> Username: admin

> Password: password123

## Overview

This project models as a library for basic 2D graphical objects.
The goal is to exercise C++ fundamentals to construct this project
such as inheritance, aggregation, polymorphism, exception handling,
templates, operator overloading, and move semantics. There is a
Shape class interface that allows all other shapes to derive from it.
To store these shapes, a custom vector class is implemented using a
basic iterator member type with `begin()` and `end()` methods.
To sort the vector of shape objects, a custom selection sort algorithm
is implemented using templated functions to compare perimeter and area.

The program is created using the gui library [Qt](https://github.com/qt). Specifically `QPainter`
and `QWidgets` are used to render shapes and text on the screen. The user
interface is designed to be readable and simple, while still being able to handle
contingencies such as invalid input. In addition to output of text
and shapes in the window, the program allows a user to manipulate size, color,
and location.

Our team has strongly enforced an agile development methodology. These methods include:

- Following a scrum procress of assigning a scrum master, product owner and team member role
- Creating user stories to help with the implementation of features
- Creating UML class diagrams, both use case and state diagrams

## User Interface Design

- Choose demo shapes using a header pane
- A collapsable side navigation bar to modify any default attribute of a given shape
- Settings header pane for user settings, contact information, and save and exit

## Sprints

| (Sprint #1) Estimated Time: 3 weeks |
| :---------------------------------: |

- [x] Implement shapes.txt parser object/logic
- [x] Implement vector container
- [x] Begin implementation of shape abc interface & inheritance hierarchy (line, polyline ...)
- [x] Investigate/understand qt qpainter demo project
- [x] Build basic 2d modeler qt project with login screen

<br />

| (Sprint #2) Estimated Time: 3 weeks |
| :---------------------------------: |

- [x] Complete implementation of shape abc interface & inheritance hierarchy (line, polyline ...)
- [x] Ability to render 2d shapes (2d modeler qt project)
- [x] Renderarea widget (inherits from qwidget like qt 2d rendering demo project) can dislpay all geometric shapes
- [x] Ability to render all shapes from shapes.txt in renderarea widget (2d modeler qt project)
- [x] Reports to display shapes, shape perimeter & area (2d modeler qt project)
- [x] Update 2d shapes (i.e. add, remove or move) via rendering widget forms (2d modeler qt project)
- [x] Persist changes to shapes.txt file

<br />

| General Requirement List |
| :----------------------: |

- [x] Use inheritance
- [x] Use aggregation
- [x] Use exception handling
- [x] Use a virtual function
- [x] Use at least two overload operators
- [x] At least one class using templates
- [x] At least one class must contain a pointer (write copy constructor and test it)
- [x] Invalid inputs should be addressed.
- [x] Doxygen documentation
- [ ] Valgrind memory leak check
- [ ] Guests should be able to enter "satisfied customer" testimonials that persist between executions.
- [x] Provide "Contact us" method with team name and logo
