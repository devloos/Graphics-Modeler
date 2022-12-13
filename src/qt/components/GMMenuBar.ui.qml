import QtQuick 6.4
import QtQuick.Controls 6.4
import QtQuick.Window 6.4
import QtQuick.Controls.Material 2.3

MenuBar {
    height: 40

    anchors {
        left: parent.left
        right: parent.right
        top: parent.top
    }

    Material.theme: Material.Dark
    Material.accent: Material.Purple

    Menu {
        title: qsTr("&File")

        MenuItem {
            text: qsTr("&Open...")
            onTriggered: fileDialog.open()
        }

        MenuItem {
            text: qsTr("&Save...")
        }

        MenuSeparator {}

        MenuItem {
            text: qsTr("&Quit")
            onTriggered: Qt.quit()
        }
    }

    Menu {
        title: qsTr("&Reports")

        MenuItem {
            text: qsTr("&Run Report...")
            onTriggered: menu_bar.runReport()
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
            onTriggered: contact_us_popup.open()
        }

        MenuItem {
            text: qsTr("&Meet the Team...")
            onTriggered: meet_the_team_popup.open()
        }

        MenuSeparator {}

        MenuItem {
            text: qsTr("&Logout...")
            onTriggered: window.logout()
        }
    }
}
