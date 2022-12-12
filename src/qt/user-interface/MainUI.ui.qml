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

    ShapeSelector {
      id: left_side_bar
    }

    GMMenuBar {
        id: menu_bar
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

    ShapePropertiesPane {
        id: shape_properties_pane
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.66}D{i:30}D{i:37}
}
##^##*/

