import QtQuick 6.4
import QtQuick.Controls 6.4
import QtQuick.Window 6.4
import QtQuick.Controls.Material 2.3

Rectangle {
    property alias meet_the_team_back_btn: meet_the_team_back_btn

    readonly property int _MEET_THE_TEAM_WIDTH: 580
    readonly property int _MEET_THE_TEAM_HEIGHT: 420

    Material.theme: Material.Dark
    Material.accent: Material.Purple

    x: window._MAIN_WIDTH / 2 - _MEET_THE_TEAM_WIDTH / 2
    y: window._MAIN_HEIGHT / 2 - _MEET_THE_TEAM_HEIGHT / 2 
    width: _MEET_THE_TEAM_WIDTH
    height: _MEET_THE_TEAM_HEIGHT

    color: "#00bdbdbd"
    border.color: "#ffffff"
    border.width: 0

    Rectangle {
        x: 0 
        y: 0
        width: _MEET_THE_TEAM_WIDTH
        height: _MEET_THE_TEAM_HEIGHT

        color: "#2f2f2f"
        radius: 14
        border.color: "#ce93d8"
        border.width: 4

        Label {
            x: 0
            y: 16
            color: "#ffffff"
            text: qsTr("Meet the Team")
            anchors.horizontalCenterOffset: 0
            font.pointSize: 20
            font.bold: true
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Button {
            id: meet_the_team_back_btn
            x: 483
            y: 348
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

        Image {
            id: cameronImage
            x: 292
            y: 162
            width: 100
            height: 100
            source: "Cameron.png"
            z: 0
            fillMode: Image.PreserveAspectFit

            Image {
                id: image1
                x: 6
                y: 6
                width: 100
                height: 100
                opacity: 0.3
                source: "shadow.png"
                z: -1
                fillMode: Image.PreserveAspectFit
            }
        }

        Image {
            id: carlosImage
            x: 292
            y: 56
            width: 100
            height: 100
            source: "Carlos.png"
            z: 0
            fillMode: Image.PreserveAspectFit
            Image {
                id: image2
                x: 6
                y: 6
                width: 100
                height: 100
                opacity: 0.3
                source: "shadow.png"
                z: -1
                fillMode: Image.PreserveAspectFit
            }
        }

        Image {
            id: liamImage
            x: 34
            y: 162
            width: 100
            height: 100
            source: "Liam.png"
            z: 0
            fillMode: Image.PreserveAspectFit
            Image {
                id: image3
                x: 6
                y: 6
                width: 100
                height: 100
                opacity: 0.3
                source: "shadow.png"
                z: -1
                fillMode: Image.PreserveAspectFit
            }
        }

        Image {
            id: connorImage
            x: 34
            y: 56
            width: 100
            height: 100
            source: "Connor.png"
            z: 0
            fillMode: Image.PreserveAspectFit
            Image {
                id: image4
                x: 6
                y: 6
                width: 100
                height: 100
                opacity: 0.3
                source: "shadow.png"
                z: -1
                fillMode: Image.PreserveAspectFit
            }
        }

        Image {
            id: josephImage
            x: 34
            y: 268
            width: 100
            height: 100
            source: "Joseph.png"
            z: 0
            fillMode: Image.PreserveAspectFit
            Image {
                id: image5
                x: 6
                y: 6
                width: 100
                height: 100
                opacity: 0.3
                source: "shadow.png"
                z: -1
                fillMode: Image.PreserveAspectFit
            }
        }

        Label {
            id: label
            x: 140
            y: 94
            text: qsTr("Connor  D.")
            font.pointSize: 16
        }

        Label {
            id: label1
            x: 398
            y: 94
            text: qsTr("Carlos A.")
            font.pointSize: 16
        }

        Label {
            id: label2
            x: 140
            y: 198
            text: qsTr("Liam E.")
            font.pointSize: 16
        }

        Label {
            id: label3
            x: 398
            y: 198
            text: qsTr("Cameron R.")
            font.pointSize: 16
        }

        Label {
            id: label4
            x: 140
            y: 306
            text: qsTr("Joseph B.")
            font.pointSize: 16
        }

        Text {
            id: text1
            x: 272
            y: 268
            color: "#ffffff"
            text: qsTr("\"We are the shadows in the night.\nThe ones who are not afraid to fight.\nFighting only for what is right.\nWE ARE THE SCRUMMY BOYS!\"")
            font.pixelSize: 16
            horizontalAlignment: Text.AlignHCenter
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
