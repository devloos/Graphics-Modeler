

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick 6.4
import QtQuick.Controls 6.4
import QtQuick.Window 6.4
import QtQuick.Controls.Material 2.3

Rectangle {

    width: 1080
    height: 720

    color: "#c2c2c2"
    border.color: "#ffffff"
    Material.theme: Material.Dark
    Material.accent: Material.Purple

    Rectangle {
        id: rectangle1
        width: 109
        color: "#1e1e1e"
        border.width: 0
        anchors.left: parent.left
        anchors.top: menuBar.bottom
        anchors.bottom: parent.bottom
        anchors.leftMargin: 0
        anchors.bottomMargin: 0
        anchors.topMargin: 0
        z: 2
        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#754878"
            }

            GradientStop {
                position: 1
                color: "#000000"
            }

            orientation: Gradient.Vertical
        }

        ComboBox {
            id: comboBox
            height: 28
            model: ["Select", "Line", "Polyline", "Polygon", "Rectangle", "Square", "Ellipse", "Circle", "Text"]
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            topInset: 0
            rightPadding: 0
            bottomInset: 0
            z: 1
            wheelEnabled: false
            flat: true
            spacing: 0
            anchors.rightMargin: 0
            anchors.leftMargin: 0
            anchors.topMargin: 0
        }
    }

    MenuBar {
        id: menuBar

        height: 40
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.leftMargin: 0
        anchors.rightMargin: 0
        anchors.topMargin: 0

        Material.theme: Material.Dark
        Material.accent: Material.Purple

        Menu {
            title: qsTr("&File")
            MenuItem {
                text: qsTr("&New...")
            }
            MenuItem {
                text: qsTr("&Open...")
            }
            MenuItem {
                text: qsTr("&Save")
            }
            MenuItem {
                text: qsTr("Save &As...")
            }
            MenuSeparator {}
            MenuItem {
                text: qsTr("&Quit")
            }
        }
        Menu {
            title: qsTr("&Edit")
            MenuItem {
                text: qsTr("&Left...")
            }
            MenuItem {
                text: qsTr("&Right...")
            }
        }
        Menu {
            title: qsTr("&View")
            MenuItem {
                text: qsTr("&Shapes Selector...")
                onTriggered: rectangle1.visible = !rectangle1.visible
            }
            MenuItem {
                text: qsTr("&Shape Properties...")
                onTriggered: rectangle2.visible = !rectangle2.visible
            }
        }
        Menu {
            title: qsTr("&Misc")
            MenuItem {
                text: qsTr("&Contact Us...")
            }
            MenuItem {
                text: qsTr("&Meet the Team...")
            }
            MenuSeparator {}
            MenuItem {
                text: qsTr("&Logout...")
            }
        }
    }

    ScrollView {
        id: scrollView

        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: menuBar.bottom
        anchors.bottom: parent.bottom
        anchors.rightMargin: 0
        anchors.leftMargin: 0
        anchors.bottomMargin: 0
        anchors.topMargin: 0
    }

    Rectangle {
        id: rectangle2

        x: 880
        y: 227
        width: 200
        height: 200

        color: "#754878"
        anchors.right: parent.right
        anchors.top: menuBar.bottom
        anchors.bottom: parent.bottom
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.topMargin: 0

        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#754878"
            }

            GradientStop {
                position: 1
                color: "#000000"
            }

            orientation: Gradient.Vertical
        }

        Text {
            id: text1
            y: 8
            color: "#ffffff"
            text: qsTr("Shape Properties")
            anchors.left: parent.left
            anchors.right: parent.right
            font.pixelSize: 25
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignTop
            anchors.rightMargin: 3
            anchors.leftMargin: 3
            font.family: "Arial"
        }

        Text {
            id: text2
            y: 52
            width: 73
            height: 17
            color: "#ffffff"
            text: qsTr("Shape ID:")
            anchors.left: parent.left
            font.pixelSize: 15
            anchors.leftMargin: 6
            font.family: "Arial"
        }

        Text {
            id: text3
            y: 52
            color: "#ffffff"
            text: qsTr("ID")
            anchors.left: text2.right
            font.pixelSize: 15
            anchors.leftMargin: 0
            font.family: "Arial"
        }

        Text {
            id: text4
            y: 75
            width: 98
            height: 17
            color: "#ffffff"
            text: qsTr("Shape Name:")
            anchors.left: parent.left
            font.pixelSize: 15
            anchors.leftMargin: 6
            font.family: "Arial"
        }

        Text {
            id: text5
            y: 75
            color: "#ffffff"
            text: qsTr("Name")
            anchors.left: text4.right
            font.pixelSize: 15
            anchors.leftMargin: 0
            font.family: "Arial"
        }

        Text {
            id: text6
            y: 98
            width: 54
            height: 17
            color: "#ffffff"
            text: qsTr("Length:")
            anchors.left: parent.left
            font.pixelSize: 15
            anchors.leftMargin: 6
            font.family: "Arial"
        }

        TextEdit {
            id: textEdit
            y: 98
            width: 80
            height: 20
            color: "#ffffff"
            text: qsTr("Edit Me")
            anchors.left: text6.right
            font.pixelSize: 15
            anchors.leftMargin: 0
            font.family: "Arial"
        }

        Rectangle {
            id: rectangle3
            y: 38
            height: 8
            color: "#434343"
            border.color: "#434343"
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.rightMargin: 7
            anchors.leftMargin: 7
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.66}D{i:30}
}
##^##*/

