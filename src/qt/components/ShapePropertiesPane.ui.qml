import QtQuick 6.4
import QtQuick.Controls 6.4
import QtQuick.Window 6.4
import QtQuick.Controls.Material 2.3

Rectangle {
    x: 880
    y: 227
    width: 350
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

    Rectangle {
        y: 44
        height: 0.5
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.rightMargin: 7
        anchors.leftMargin: 7
    }
}