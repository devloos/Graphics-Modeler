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

    anchors {
        right: parent.right
        top: menu_bar.bottom
        bottom: parent.bottom
    }

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
        anchors {
            left: parent.left
            right: parent.right
            rightMargin: 3
            leftMargin: 3
        }

        color: "#ffffff"
        text: qsTr("Shape Properties")

        font {
            family: "Helvetica"
            bold: true
            pixelSize: 25
        }

        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignTop
    }

    Rectangle {
        y: 44
        height: 0.5
        anchors {
            left: parent.left
            right: parent.right
            rightMargin: 7
            leftMargin: 7
        }
    }
}