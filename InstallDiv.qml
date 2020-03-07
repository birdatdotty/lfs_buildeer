import QtQuick 2.12

import QtQuick.Controls 1.2
import QtQuick.Layouts 1.12

import Step2 1.0;

GroupBox {
    property string name: ""
    property alias textArea: txtArea
    title: name
    ColumnLayout {
        anchors.fill: parent
        spacing: 0

        TextArea {
            id: txtArea
            readOnly: true
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.alignment: Qt.AlignLeft | Qt.AlignTop
        }
        RowLayout {
            Button {
                Layout.fillWidth: true
                text: "Очистить"
                onClicked: textArea.text = ""
            }
            Button {
                Layout.fillWidth: true
                text: "Установить"
                enabled: !Step2.doInstall;
                onClicked: {
                    textArea.text = ""
                    Step2.install()
                }
            }
        }
    }
}
