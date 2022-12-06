

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
    anchors.fill: parent
    color: "#c2c2c2"
    border.color: "#ffffff"

    Material.theme: Material.Dark
    Material.accent: Material.Purple

    Rectangle {
        id: rectangle1
        width: 42
        color: "#ffffff"
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0

        ToolButton {
            id: toolButton
            height: 28
            text: qsTr("Tool Button")
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.rightMargin: 0
            anchors.leftMargin: 0
            anchors.topMargin: 0
        }
    }

    ToolBar {
        id: toolBar
        height: 29
        anchors.left: rectangle1.right
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.rightMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
    }

    ScrollView {
        id: scrollView
        anchors.left: rectangle1.right
        anchors.right: parent.right
        anchors.top: toolBar.bottom
        anchors.bottom: parent.bottom
        rotation: 0.241
        anchors.leftMargin: 0
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.topMargin: 0
    }
}
