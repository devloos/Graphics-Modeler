import QtQuick 6.4
import QtQuick.Controls 6.4
import QtQuick.Window 6.4
import QtQuick.Controls.Material 2.3

Rectangle {
      width: 135
      z: 2

      color: "#4D4949"
      border.width: 0

      anchors {
        left: parent.left
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
  }