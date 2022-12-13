import QtQuick 6.4
import QtQuick.Controls 6.4
import QtQuick.Window 6.4
import QtQuick.Controls.Material 2.3

Rectangle {
      width: 135
      z: 2

      color: "#4D4949"
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
              color: "#646060"
          }

          GradientStop {
              position: 1
              color: "#000000"
          }

          orientation: Gradient.Vertical
      }
  }