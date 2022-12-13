import QtQuick 6.4
import QtQuick.Controls 6.4
import QtQuick.Window 6.4
import QtQuick.Controls.Material 2.3

Rectangle {
    readonly property int _MEET_THE_TEAM_WIDTH: 580
    readonly property int _MEET_THE_TEAM_HEIGHT: 420

    Material.theme: Material.Dark
    Material.accent: Material.Purple

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
        font.pointSize: 20
        font.bold: true
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Button {
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
        onClicked: parent_meet_the_team.close()
    }

    Image {
        x: 292
        y: 162
        width: 100
        height: 100
        source: "Cameron.png"
        z: 0
        fillMode: Image.PreserveAspectFit

        ImageShadow {}
    }

    Image {
        x: 292
        y: 56
        width: 100
        height: 100
        source: "Carlos.png"
        z: 0
        fillMode: Image.PreserveAspectFit

        ImageShadow {}
    }

    Image {
        x: 34
        y: 162
        width: 100
        height: 100
        source: "Liam.png"
        z: 0
        fillMode: Image.PreserveAspectFit

        ImageShadow {}
    }

    Image {
        x: 34
        y: 56
        width: 100
        height: 100
        source: "Connor.png"
        z: 0
        fillMode: Image.PreserveAspectFit

        ImageShadow {}
    }

    Image {
        x: 34
        y: 268
        width: 100
        height: 100
        source: "Joseph.png"
        z: 0
        fillMode: Image.PreserveAspectFit

        ImageShadow {}
    }

    Label {
        x: 140
        y: 94
        text: qsTr("Connor  D.")
        font.pointSize: 16
    }

    Label {
        x: 398
        y: 94
        text: qsTr("Carlos A.")
        font.pointSize: 16
    }

    Label {
        x: 140
        y: 198
        text: qsTr("Liam E.")
        font.pointSize: 16
    }

    Label {
        x: 398
        y: 198
        text: qsTr("Cameron R.")
        font.pointSize: 16
    }

    Label {
        x: 140
        y: 306
        text: qsTr("Joseph B.")
        font.pointSize: 16
    }

    Text {
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
