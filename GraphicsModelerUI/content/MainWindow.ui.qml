

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

    id: rectangle
    width: 640
    height: 480

    color: "#c2c2c2"
    border.color: "#ffffff"

    Material.theme: Material.Dark
    Material.accent: Material.Purple

    Rectangle {
        id: rectangle1
        width: 95
        color: "#1e1e1e"
        border.width: 0
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.leftMargin: 0
        anchors.bottomMargin: 0
        anchors.topMargin: 0
        z: 2

        ComboBox {
            id: comboBox
            height: 26
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
        x: 133
        y: 32
        width: 310
        height: 40

        MenuBarItem {}

        //        Menu {
        //            title: qsTr("&File")
        //            Action {
        //                text: qsTr("&New...")
        //            }
        //            Action {
        //                text: qsTr("&Open...")
        //            }
        //            Action {
        //                text: qsTr("&Save")
        //            }
        //            Action {
        //                text: qsTr("Save &As...")
        //            }
        //            MenuSeparator {}
        //            Action {
        //                text: qsTr("&Quit")
        //            }
        //        }
    }

    //    ToolBar {
    //        id: toolBar
    //        height: 26
    //        position: ToolBar.Header
    //        anchors.left: rectangle1.right
    //        anchors.right: parent.right
    //        anchors.top: parent.top
    //        anchors.rightMargin: 0
    //        anchors.leftMargin: 0
    //        anchors.topMargin: 0

    //        ToolButton {
    //            id: toolButton
    //            x: 0
    //            width: 43
    //            text: qsTr("File")
    //            anchors.top: parent.top
    //            anchors.bottom: parent.bottom
    //            checked: false
    //            checkable: true
    //            anchors.bottomMargin: 0
    //            anchors.topMargin: 0
    //        }

    //        ToolButton {
    //            id: toolButton1
    //            width: 43
    //            text: qsTr("Edit")
    //            anchors.left: toolButton.right
    //            anchors.top: parent.top
    //            anchors.bottom: parent.bottom
    //            highlighted: false
    //            flat: false
    //            down: false
    //            checkable: true
    //            anchors.leftMargin: 0
    //            anchors.bottomMargin: 0
    //            anchors.topMargin: 0
    //        }

    //        ToolButton {
    //            id: toolButton2
    //            width: 51
    //            text: qsTr("AUX")
    //            anchors.left: toolButton1.right
    //            anchors.top: parent.top
    //            anchors.bottom: parent.bottom
    //            checkable: true
    //            anchors.leftMargin: 0
    //            anchors.bottomMargin: 0
    //            anchors.topMargin: 0
    //        }
    //    }
    ScrollView {
        id: scrollView
        anchors.left: rectangle1.right
        anchors.right: parent.right
        anchors.top: toolBar.bottom
        anchors.bottom: parent.bottom
        anchors.rightMargin: 0
        anchors.leftMargin: 0
        anchors.bottomMargin: 0
        anchors.topMargin: 0
    }
    states: [
        State {
            name: "State1"
            when: comboBox.currentIndex == 1

            PropertyChanges {
                target: scrollView
                visible: true
            }
        }
    ]
}
