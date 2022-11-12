# 2D Graphics Modeler

__Contributers: Puwya, connor-darling, Supernova1114, Catatonic2003, jbobby0__

## Overview 
This project models as a library for basic 2D graphical objects.
The goal is exercise C++ fundamentals to construct this project
such as inheritance, aggregation, polymorphism, exception handling,
templates, operator overloading, and move semantics. The software 
is created using the Graphical User Inferace library `Qt`. 
Specifically QPainter and QWidgets are used to render shapes 
and text on the screen. A custom vector class is implemented to 
store 2D graphics objects. The interface is designed to be readable
and simple, why still handling contingencies such as invalid input.
In addition to an output of text and shapes in the window, the program
allows a user to manipulate size, color, and location.

## Sprints

  | (Sprint #1) Estimated Time: 3 weeks |
  | :---------------------------------: |
- [ ] implement shapes.txt parser object/logic  
- [ ] implement vector container 
- [ ] begin implementation of shape abc interface & inheritance hierarchy (line, polyline ...) 
- [ ] investigate/understand qt qpainter demo project 
- [ ] build basic 2d modeler qt project with login screen 
  
<br/>

  | (Sprint #2) Estimated Time: 3 weeks |
  | :---------------------------------: |
- [ ] complete implementation of shape abc interface & inheritance hierarchy (line, polyline ...)
- [ ] ability to render 2d shapes (2d modeler qt project)
- [ ] renderarea widget (inherits from qwidget like qt 2d rendering demo project) can dislpay all geometric shapes
- [ ] ability to render all shapes from shapes.txt in renderarea widget (2d modeler qt project)
- [ ] reports to display shapes, shape perimeter & area (2d modeler qt project)
- [ ] update 2d shapes (i.e. add, remove or move) via rendering widget forms (2d modeler qt project)
- [ ] persist changes to shapes.txt file