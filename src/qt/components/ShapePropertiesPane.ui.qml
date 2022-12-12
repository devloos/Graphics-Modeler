import QtQuick 6.4
import QtQuick.Controls 6.4
import QtQuick.Window 6.4
import QtQuick.Controls.Material 2.3

Rectangle {
    x: 880
    y: 227
    width: 275
    height: 200

    color: "#646060"

    anchors.right: parent.right
    anchors.top: menu_bar.bottom
    anchors.bottom: parent.bottom
    anchors.rightMargin: 0
    anchors.bottomMargin: 0
    anchors.topMargin: 0

    gradient: Gradient {
        GradientStop {
            position: 0
            color: "#646060"
        }

        GradientStop {
            position: 1
            color: "#000000"
        }

        orientation: Gradient.Vertical
    }

    Text {
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
        font.family: "Helvetica"
        font.bold: true
    }

    // TODO: link all this properly
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
        font.bold: true
    }

    Text {
        y: 52
        color: "#ffffff"
        text: qsTr("ID")
        anchors.left: text2.right
        font.pixelSize: 15
        anchors.leftMargin: 0
        font.family: "Arial"
        font.bold: true
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
        font.bold: true
    }

    Text {
        y: 75
        color: "#ffffff"
        text: qsTr("Name")
        anchors.left: text4.right
        font.pixelSize: 15
        anchors.leftMargin: 0
        font.family: "Arial"
        font.bold: true
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
        font.bold: true
    }

    TextEdit {
        y: 98
        width: 80
        height: 20
        color: "#ffffff"
        text: qsTr("Edit Me")
        anchors.left: text6.right
        font.pixelSize: 15
        anchors.leftMargin: 0
        font.family: "Arial"
        font.bold: true
    }

    Rectangle {
        y: 44
        height: 0.5
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.rightMargin: 7
        anchors.leftMargin: 7
    }
}