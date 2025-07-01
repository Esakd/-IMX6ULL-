import QtQuick 2.9
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtQuick.Window 2.12
import QtQuick.VirtualKeyboard 2.2
import radio 1.0

Item {
    width: 1024
    height: 600
    focus: true

    // 虚拟键盘组件
    InputPanel {
        id: inputPanel
        z: 88
        y: parent.height
        width: parent.width
        active: nameInput.focus

        states: State {
            name: "visible"
            when: inputPanel.active
            PropertyChanges {
                target: inputPanel
                y: parent.height - inputPanel.height
            }
        }

        transitions: Transition {
            from: ""
            to: "visible"
            reversible: true
            ParallelAnimation {
                NumberAnimation {
                    properties: "y"
                    duration: 250
                    easing.type: Easing.InOutQuad
                }
            }
        }
    }

    // 底部面板 - 输入法出现时的占位符
    Rectangle {
        id: pannelbg
        z: 87
        width: parent.width
        anchors.bottom: inputPanel.top
        height: inputPanel.state == "visible" ? 20 : 0
        color: "transparent"
    }

    // 背景渐变
    Rectangle {
        anchors.fill: parent
        gradient: Gradient {
            GradientStop { position: 0.0; color: "#1E90FF" }
            GradientStop { position: 1.0; color: "#87CEEB" }
        }
    }

    // 学生名单管理
    MyRadio {
        id: rollCallManager

        onNamesChanged: {
            var names = getNames();
            nameListModel.clear();
            for (var i = 0; i < names.length; i++) {
                nameListModel.append({ "name": names[i] });
            }
        }

        onNameCalled: function(name) {
            rollingText.text = name;
        }
    }

    // 主容器（管理布局高度）
    Item {
        id: container
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: inputPanel.active ? pannelbg.top : parent.bottom
        anchors.margins: 20
        anchors.bottomMargin: 10

        RowLayout {
            anchors.fill: container
            spacing: 20

            // 左侧学生列表区（可滚动）
            ColumnLayout {
                Layout.preferredWidth: 400
                Layout.fillHeight: true

                // 列表视图（锚定到父容器顶部）
                ListView {
                    id: nameListView
                    clip: true
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    model: ListModel {
                        id: nameListModel
                    }
                    delegate: ItemDelegate {
                        width: parent.width
                        text: "姓名：" + model.name
                    }

                    // 强制锚定到父容器顶部
                    anchors.top: parent.top
                    anchors.topMargin: 0
                }

                // 输入框和添加按钮
                RowLayout {
                    spacing: 10
                    Layout.alignment: Qt.AlignLeft

                    TextField {
                        id: nameInput
                        placeholderText: "输入学生姓名"
                        Layout.preferredWidth: 200
                        inputMethodHints: Qt.ImhNoPredictiveText

                        onAccepted: {
                            if (text.trim() !== "") {
                                rollCallManager.addName(text.trim());
                                text = "";
                                focus = false; // 隐藏输入法
                            }
                        }

                        onFocusChanged: {
                            // 自动处理输入法状态
                            if (focus) {
                                Qt.inputMethod.show();
                            } else {
                                Qt.inputMethod.hide();
                            }
                        }
                    }

                    Button {
                        text: "添加"
                        Layout.preferredWidth: 60
                        onClicked: {
                            if (nameInput.text.trim() !== "") {
                                rollCallManager.addName(nameInput.text.trim());
                                nameInput.text = "";
                                nameInput.focus = false; // 隐藏输入法
                            }
                        }
                    }
                }
            }

            // 右侧面板：点名展示 + 操作按钮
            ColumnLayout {
                Layout.preferredWidth: 300
                Layout.fillHeight: true
                spacing: 30

                Rectangle {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    radius: 15
                    color: "#ffffff"
                    opacity: 0.8

                    Text {
                        id: rollingText
                        text: "开始点名..."
                        font.pixelSize: 36
                        font.bold: true
                        color: "#1E90FF"
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        anchors.centerIn: parent

                        Behavior on text {
                            NumberAnimation {
                                duration: 100
                                easing.type: Easing.InOutQuad
                            }
                        }
                    }
                }

                ColumnLayout {
                    spacing: 30
                    Layout.alignment: Qt.AlignTop

                    Button {
                        text: "开始"
                        Layout.fillWidth: true
                        Layout.preferredHeight: 60
                        font.bold: true
                        background: Rectangle {
                            color: "#32CD32"
                            radius: 10
                        }
                        onClicked: {
                            if (rollCallManager.getNames().length === 0) {
                                rollingText.text = "请先添加学生姓名";
                                return;
                            }
                            randomTimer.start();
                        }
                    }

                    Button {
                        text: "停止"
                        Layout.fillWidth: true
                        Layout.preferredHeight: 60
                        font.bold: true
                        background: Rectangle {
                            color: "#DC143C"
                            radius: 10
                        }
                        onClicked: {
                            randomTimer.stop();
                        }
                    }

                    Button {
                        text: "顺序点名"
                        Layout.fillWidth: true
                        Layout.preferredHeight: 60
                        font.bold: true
                        background: Rectangle {
                            color: "#FFD700"
                            radius: 10
                        }
                        onClicked: {
                            rollCallManager.startCall();
                        }
                    }
                }
            }
        }
    }

    // 随机点名定时器
    Timer {
        id: randomTimer
        interval: 100
        repeat: true
        onTriggered: {
            if (rollCallManager.getNames().length > 0) {
                rollCallManager.randomCall();
            } else {
                randomTimer.stop();
                rollingText.text = "学生名单已清空";
            }
        }
    }
}
