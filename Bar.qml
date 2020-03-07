import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.3
import QtQuick.Window 2.2

MenuBar {


        Menu {
            title: "File"
            MenuItem {
                text: "Open Model.qml ...";
                onTriggered: console.log("Open...")
            }
            MenuItem { text: "Open Pkgs.qml ..."; onTriggered: console.log("Open...") }
            MenuItem { text: "Close" ; onTriggered: Qt.quit() }
        }

        Menu {
            title: "Options"
//            MenuItem { text: "Cut"; checkable: true}
            MenuItem { text: "wget" }
            MenuItem { text: "wget_out" }
            MenuItem { text: "tar" }
            MenuSeparator {visible: true }
            MenuItem { text: "scriptsDir" }
            MenuItem { text: "sourcesDir" }
            MenuItem { text: "buildDir" }
            MenuSeparator {visible: true }
            MenuItem { text: "bash" }
        }
    }
