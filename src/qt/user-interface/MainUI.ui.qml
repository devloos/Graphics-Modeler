import QtQuick 6.4
import QtQuick.Controls 6.4
import QtQuick.Window 6.4
import QtQuick.Controls.Material 2.3

Rectangle {
    width: window._MAIN_WIDTH
    height: window._MAIN_HEIGHT

    color: "#c2c2c2"
    border.color: "#ffffff"
    Material.theme: Material.Dark
    Material.accent: Material.Purple


    Rectangle {
        id: left_side_bar

        width: 135
        z: 2

        color: "#1e1e1e"
        border.width: 0

        anchors.left: parent.left
        anchors.top: menu_bar.bottom
        anchors.bottom: parent.bottom
        anchors.leftMargin: 0
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

        ComboBox {
            id: shape_selector
            height: 28
            z: 1

            model: ["Select", "Line", "Polyline", "Polygon", "Rectangle", "Square", "Ellipse", "Circle", "Text"]

            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.rightMargin: 0
            anchors.leftMargin: 0
            anchors.topMargin: 0

            topInset: 0
            rightPadding: 0
            bottomInset: 0
            wheelEnabled: false
            flat: true
            spacing: 0

            onActivated: (index) => {
                switch (index) {
                    case 1: {
                        loader.sourceComponent = line
                        break;
                    }

                    case 2: {
                        loader.sourceComponent = polyline
                        break;
                    }

                    case 3: {
                        loader.sourceComponent = polygon
                        break;
                    }

                    case 4: {
                        loader.sourceComponent = rectangle
                        break;
                    }

                    case 5: {
                        loader.sourceComponent = square
                        break;
                    }

                    case 6: {
                        loader.sourceComponent = ellipse
                        break;
                    }

                    case 7: {
                        loader.sourceComponent = circle
                        break;
                    }

                    case 8: {
                        loader.sourceComponent = text
                        break;
                    }

                    default: {
                        loader.sourceComponent = undefined
                        break;
                    }
                }
            }
        }
    }

    MenuBar {
        id: menu_bar

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
                onTriggered: Qt.quit()
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
                text: qsTr("&Toggle Selector...")
                onTriggered: left_side_bar.visible = !left_side_bar.visible
            }

            MenuItem {
                text: qsTr("&Toggle Properties...")
                onTriggered: shape_properties_pane.visible = !shape_properties_pane.visible
            }
        }

        Menu {
            title: qsTr("&Misc")

            MenuItem {
                text: qsTr("&Contact Us...")
                onTriggered: contact_us_popup.open(window._MAIN_WIDTH, window._MAIN_HEIGHT)
            }

            MenuItem {
                text: qsTr("&Meet the Team...")
            }

            MenuSeparator {}

            MenuItem {
                text: qsTr("&Logout...")
                onTriggered: window.logout()
            }
        }
    }

    ScrollView {
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: menu_bar.bottom
        anchors.bottom: parent.bottom
        anchors.rightMargin: 0
        anchors.leftMargin: 0
        anchors.bottomMargin: 0
        anchors.topMargin: 0
    }

    Rectangle {
        id: shape_properties_pane

        x: 880
        y: 227
        width: 275
        height: 200

        color: "#754878"

        anchors.right: parent.right
        anchors.top: menu_bar.bottom
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
        }

        Text {
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
            y: 38
            height: 8
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.rightMargin: 7
            anchors.leftMargin: 7
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.66}D{i:30}D{i:37}
}
##^##*/

