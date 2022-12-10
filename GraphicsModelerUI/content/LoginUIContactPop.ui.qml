

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
    Material.theme: Material.Dark
    Material.accent: Material.Purple

    id: background
    x: 0
    y: 0
    width: 584
    height: 424
    color: "#00bdbdbd"
    radius: 14
    border.color: "#ffffff"
    border.width: 0

    Rectangle {
        id: background1
        x: 28
        y: 28
        width: 584
        height: 424
        color: "#bdbdbd"
        radius: 14
        border.color: "#ffffff"
        border.width: 0

        Rectangle {
            id: rectangleBruh2
            x: 8
            y: 8
            width: 568
            height: 408
            color: "#2f2f2f"
            radius: 14
            border.color: "#6f4b75"
            border.width: 0

            TextField {
                id: textField3
                x: 118
                y: 104
                width: 332
                height: 46
                placeholderText: qsTr("Email")
            }

            TextArea {
                id: textArea1
                x: 118
                y: 158
                width: 332
                height: 172
                placeholderText: qsTr("Write something . . .")
            }

            Label {
                id: label3
                x: 143
                y: 38
                color: "#ffffff"
                text: qsTr("Give us your Feedback")
                font.pointSize: 20
                font.bold: true
            }

            Button {
                id: button3
                x: 203
                y: 340
                width: 162
                height: 48
                text: qsTr("Send!")
                font.letterSpacing: 0
                font.capitalization: Font.Capitalize
                hoverEnabled: true
                font.bold: true
                checkable: false
                down: false
                flat: true
                checked: false
                highlighted: true
            }

            Button {
                id: button4
                x: 476
                y: 340
                width: 72
                height: 48
                text: qsTr("Back")
                font.letterSpacing: 0
                font.capitalization: Font.Capitalize
                hoverEnabled: true
                font.bold: true
                checkable: false
                down: false
                checked: false
                flat: true
                highlighted: true
            }

            gradient: Gradient {
                orientation: Gradient.Vertical
                GradientStop {
                    position: 0
                    color: "#434343"
                }

                GradientStop {
                    position: 1
                    color: "#000000"
                }
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/

