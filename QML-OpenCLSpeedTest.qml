import QtQuick 2.1
import QtQuick.Controls 1.0
import QtQuick.Window 2.0
import QtQuick.Layouts 1.0

ApplicationWindow {
    title: qsTr("OpenCL Speed Tester")
    width: 640
    height: 480
    Column {
        anchors.fill: parent
        spacing: 10
        anchors.margins: 10

        ComboBox {
            width: parent.width

            model: ListModel {
                id: ddItems
                ListElement {text: "AMD Radeon HD 5770"}
                ListElement {text: "NVIDIA 670"}
                ListElement {text: "Intel 3770"}
            }
            onCurrentIndexChanged: console.debug(currentText + ", " + currentIndex)
        }

        TextArea {
            width: parent.width
            text: "Regel 1\r\nRegel 2\r\nRegel 3"
            readOnly: true
        }

        GridLayout {
            width: parent.width
            columnSpacing: 20

            id: grid
            columns: 3
            // Row 1
            Item { Layout.fillWidth: true; }
            Text { Layout.fillWidth: true; text: "Read (GB/s)" }
            Text { Layout.fillWidth: true; text: "Write (GB/s)" }

            // Row 2
            Text { Layout.alignment: Qt.AlignVCenter | Qt.AlignRight; text: "Global" }
            TextInputCustom { }
            TextInputCustom { }

            // Row 3
            Text { Layout.alignment: Qt.AlignVCenter | Qt.AlignRight; text: "Local" }
            TextInputCustom { }
            TextInputCustom { }

            // Row 4
            Text { Layout.alignment: Qt.AlignVCenter | Qt.AlignRight; text: "Private" }
            TextInputCustom { }
            TextInputCustom { }
        }
    }
}
