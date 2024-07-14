import QtQuick 2.15
import Qt.labs.qmlmodels
import QtQuick.Dialogs

Item{
    id: f
    //anchors.fill: parent

    y: 0
    x: 0
    //property double zoom: 1
    property int rowHeight: 30
    property int nameWidth: rowHeight * 6

    property font currentFont: Qt.font({
                                           family: "Arial",
                                           bold: true,
                                           italic: true,
                                           pixelSize: 10
                                       })

    // contentWidth: rowHeight * 10  + nameWidth * 2
    // contentHeight: rowHeight * 12

    property int drawOne: 1
    property int drawTwo: 2
    property int drawThree: 3
    property int drawFour: 4

    property string nameOne: "Иванов Иван"
    property string nameTwo: "Петров Петр"
    property string nameThree: "Сидоров Александр"
    property string nameFour: "Кузнецов Семен"

    property string regionOne: "Брянская область"
    property string regionTwo: "Московская Область"
    property string regionThree: "Красноярский Край"
    property string regionFour: "Челябинская область"

    property string rangeOne: "МС"
    property string rangeTwo: "МС"
    property string rangeThree: "МС"
    property string rangeFour: "МС"

    property int drawFinalOne: 1
    property int drawFinalTwo: 2
    property int drawThirdOne: 3
    property int drawThirdTwo: 4

    property int placeOne: 1
    property int placeTwo: 2
    property int placeThree: 3

    property double result1SumBalls: 140.5
    property int result1MaxRateCount: 5

    property double result2SumBalls: 140.5
    property int result2MaxRateCount: 5

    property double result3SumBalls: 140.5
    property int result3MaxRateCount: 5

    property double result4SumBalls: 140.5
    property int result4MaxRateCount: 5

    property double resultFinal1SumBalls: 140.5
    property int resultFinal1MaxRateCount: 5

    property double resultFinal2SumBalls: 140.5
    property int resultFinal2MaxRateCount: 5

    property double resultThird1SumBalls: 140.5
    property int resultThird1MaxRateCount: 5

    property double resultThird2SumBalls: 140.5
    property int resultThird2MaxRateCount: 5

    // WheelHandler {
    //     onWheel: (wheel)=> {
    //         if (wheel.modifiers & Qt.ControlModifier) {
    //             adjustZoom(wheel.angleDelta.y / 120);
    //         }
    //     }
    // }

    // FontDialog {
    //     id: fontDialog
    //     currentFont.family: f.currentFont
    // }

    MouseArea{
        anchors.fill: parent

        onWheel: (wheel)=> {
            console.log(wheel.angleDelta)
            if(wheel.angleDelta.y > 0){
                if(rowHeight < 100)
                    rowHeight += 1
            }else{
                if(rowHeight > 10)
                    rowHeight -= 1
            }
            //parent.scale = zoom
            // console.log("zoom = " + zoom)
            // console.log(f.originX + " " + f.contentX + " " + f.x)
            // x = originX
        }

        // onMouseXChanged: {
        //     console.log("contentX = " + contentX + " " + "contentY = " + contentY )
        //     console.log("originX = " + originX + " " + "originY = " + originY )
        // }



        //onMove: {console.log("onPressed")}
    }

    //scale: 1

    // onScaleChanged: {
    //     console.log(f.originX + " " + f.contentX + " " + f.x)
    // }

    Rectangle {
        id: one
        height: rowHeight
        width: rowHeight
        border.width: 1
        Text {
            text: drawOne
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            padding: 4
        }
    }
    Rectangle {
        id: oneName
        x: rowHeight - 1
        height: rowHeight
        width: nameWidth
        border.width: 1
        Text {
            text: nameOne
            anchors.verticalCenter: parent.verticalCenter
            padding: 4
        }
    }
    Rectangle {
        id: oneRegion
        x: rowHeight + nameWidth - 2
        height: rowHeight
        width: nameWidth
        border.width: 1
        Text {
            text: regionOne
            anchors.verticalCenter: parent.verticalCenter
            padding: 4
        }
    }
    Rectangle {
        id: oneRange
        x: rowHeight + nameWidth * 2 - 3
        height: rowHeight
        width: rowHeight
        border.width: 1
        Text {
            text: rangeOne
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            padding: 4
        }
    }
    Rectangle {
        id: oneResult
        x: rowHeight * 2 + nameWidth * 2 - 4
        height: rowHeight
        width: rowHeight * 2
        border.width: 1
        Rectangle{
            height: parent.height - 2
            width: parent.width / 2 - 2
            x: 1
            y: 1
            Text{
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                text: result1SumBalls
            }
            //border.width: 1
        }
        Rectangle{
            height: parent.height - 2
            width: 1
            x: parent.width / 2
            y: 1
            color: "lightgray"
        }
        Rectangle{
            height: parent.height - 2
            width: parent.width / 2 - 2
            x: parent.width / 2 + 1
            y: 1
            Text{
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                text: result1MaxRateCount
            }
        }
    }

    Rectangle {
        id: oneTwoStatus
        x: rowHeight * 3 + nameWidth * 2 - 4
        y: rowHeight - 1
        height: rowHeight
        width: rowHeight
        border.width: 1
        color:"lightgray"
    }

    Rectangle {
        id: two
        y: rowHeight * 2 - 2
        height: rowHeight
        width: rowHeight
        border.width: 1
        Text {
            text: drawTwo
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            padding: 4
        }
    }
    Rectangle {
        id: twoName
        y: rowHeight * 2 - 2
        x: rowHeight - 1
        height: rowHeight
        width: nameWidth
        border.width: 1
        Text {
            text: nameTwo
            anchors.verticalCenter: parent.verticalCenter
            padding: 4
        }

    }
    Rectangle {
        id: twoRegion
        y: rowHeight * 2 - 2
        x: rowHeight + nameWidth - 2
        height: rowHeight
        width: nameWidth
        border.width: 1
        Text {
            text: regionTwo
            anchors.verticalCenter: parent.verticalCenter
            padding: 4
        }
    }
    Rectangle {
        id: twoRange
        y: rowHeight * 2 - 2
        x: rowHeight + nameWidth * 2 - 3
        height: rowHeight
        width: rowHeight
        border.width: 1
        Text {
            text: rangeTwo
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            padding: 4
        }
    }
    Rectangle {
        id: twoResult
        y: rowHeight * 2 - 2
        x: rowHeight * 2 + nameWidth * 2 - 4
        height: rowHeight
        width: height * 2
        border.width: 1
        Rectangle{
            height: parent.height - 2
            width: parent.width / 2 - 2
            x: 1
            y: 1
            Text{
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                text: result2SumBalls
            }
            //border.width: 1
        }
        Rectangle{
            height: parent.height - 2
            width: 1
            x: parent.width / 2
            y: 1
            color: "lightgray"
        }
        Rectangle{
            height: parent.height - 2
            width: parent.width / 2 - 2
            x: parent.width / 2 + 1
            y: 1
            Text{
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                text: result2MaxRateCount
            }
        }
    }

    Rectangle {
        id: three
        height: rowHeight
        width: rowHeight
        y: rowHeight * 4
        border.width: 1
        Text {
            text: drawThree
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            padding: 4
        }
    }
    Rectangle {
        id: threeName
        x: rowHeight - 1
        y: rowHeight * 4
        height: rowHeight
        width: nameWidth
        border.width: 1
        Text {
            text: nameThree
            anchors.verticalCenter: parent.verticalCenter
            padding: 4
        }
    }
    Rectangle {
        id: threeRegion
        x: rowHeight + nameWidth - 2
        y: rowHeight * 4
        height: rowHeight
        width: nameWidth
        border.width: 1
        Text {
            text: regionThree
            anchors.verticalCenter: parent.verticalCenter
            padding: 4
        }
    }
    Rectangle {
        id: threeRange
        x: rowHeight + nameWidth * 2 - 3
        y: rowHeight * 4
        height: rowHeight
        width: rowHeight
        border.width: 1
        Text {
            text: rangeThree
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            padding: 4
        }
    }
    Rectangle {
        id: threeResult
        x: rowHeight * 2 + nameWidth * 2 - 4
        y: rowHeight * 4
        height: rowHeight
        width: rowHeight * 2
        border.width: 1
        Rectangle{
            height: parent.height - 2
            width: parent.width / 2 - 2
            x: 1
            y: 1
            Text{
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                text: result3SumBalls
            }
            //border.width: 1
        }
        Rectangle{
            height: parent.height - 2
            width: 1
            x: parent.width / 2
            y: 1
            color: "lightgray"
        }
        Rectangle{
            height: parent.height - 2
            width: parent.width / 2 - 2
            x: parent.width / 2 + 1
            y: 1
            Text{
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                text: result3MaxRateCount
            }
        }

    }
    Rectangle {
        id: threeFourStatus
        x: rowHeight * 3 + nameWidth * 2 - 4
        y: rowHeight * 5 - 1
        height: rowHeight
        width: rowHeight
        border.width: 1
        color:"lightgray"
    }

    Rectangle {
        id: four
        y: rowHeight * 6 - 2
        height: rowHeight
        width: rowHeight
        border.width: 1
        Text {
            text: drawFour
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            padding: 4
        }
    }
    Rectangle {
        id: fourName
        y: rowHeight * 6 - 2
        x: rowHeight - 1
        height: rowHeight
        width: nameWidth
        border.width: 1
        Text {
            text: nameFour
            anchors.verticalCenter: parent.verticalCenter
            padding: 4
        }
    }
    Rectangle {
        id: fourRegion
        y: rowHeight * 6 - 2
        x: rowHeight + nameWidth - 2
        height: rowHeight
        width: nameWidth
        border.width: 1
        Text {
            text: regionFour
            anchors.verticalCenter: parent.verticalCenter
            padding: 4
        }
    }
    Rectangle {
        id: fourRange
        y: rowHeight * 6 - 2
        x: rowHeight + nameWidth * 2 - 3
        height: rowHeight
        width: rowHeight
        border.width: 1
        Text {
            text: rangeFour
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            padding: 4
        }
    }
    Rectangle {
        id: fourResult
        y: rowHeight * 6 - 2
        x: rowHeight * 2 + nameWidth * 2 - 4
        height: rowHeight
        width: rowHeight * 2
        border.width: 1
        Rectangle{
            height: parent.height - 2
            width: parent.width / 2 - 2
            x: 1
            y: 1
            Text{
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                text: result4SumBalls
            }
            //border.width: 1
        }
        Rectangle{
            height: parent.height - 2
            width: 1
            x: parent.width / 2
            y: 1
            color: "lightgray"
        }
        Rectangle{
            height: parent.height - 2
            width: parent.width / 2 - 2
            x: parent.width / 2 + 1
            y: 1
            Text{
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                text: result4MaxRateCount
            }
        }
    }

    Rectangle{
        id: finalOne
        y: rowHeight - 1
        x: rowHeight * 4 + nameWidth * 2 - 5
        height: rowHeight
        width: rowHeight
        border.width: 1
        Text {
            text: drawFinalOne
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            padding: 4
        }
    }

    Rectangle{
        id: finalOneResult
        y: rowHeight - 1
        x: rowHeight * 5 + nameWidth * 2 - 6
        height: rowHeight
        width: rowHeight * 2
        border.width: 1
        Rectangle{
            height: parent.height - 2
            width: parent.width / 2 - 2
            x: 1
            y: 1
            Text{
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                text: resultFinal1SumBalls
            }
            //border.width: 1
        }
        Rectangle{
            height: parent.height - 2
            width: 1
            x: parent.width / 2
            y: 1
            color: "lightgray"
        }
        Rectangle{
            height: parent.height - 2
            width: parent.width / 2 - 2
            x: parent.width / 2 + 1
            y: 1
            Text{
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                text: resultFinal1MaxRateCount
            }
        }
    }

    Rectangle{
        id: finalTwo
        y: rowHeight * 5 - 1
        x: rowHeight * 4 + nameWidth * 2 - 5
        height: rowHeight
        width: rowHeight
        border.width: 1
        Text {
            text: drawFinalTwo
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            padding: 4
        }
    }

    Rectangle{
        id: finalTwoResult
        y: rowHeight * 5 - 1
        x: rowHeight * 5 + nameWidth * 2 - 6
        height: rowHeight
        width: rowHeight * 2
        border.width: 1
        Rectangle{
            height: parent.height - 2
            width: parent.width / 2 - 2
            x: 1
            y: 1
            Text{
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                text: resultFinal2SumBalls
            }
            //border.width: 1
        }
        Rectangle{
            height: parent.height - 2
            width: 1
            x: parent.width / 2
            y: 1
            color: "lightgray"
        }
        Rectangle{
            height: parent.height - 2
            width: parent.width / 2 - 2
            x: parent.width / 2 + 1
            y: 1
            Text{
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                text: resultFinal2MaxRateCount
            }
        }
    }

    Rectangle{
        id: finalStatus
        y: rowHeight * 3
        x: rowHeight * 6 + nameWidth * 2 - 6
        height: rowHeight
        width: rowHeight
        border.width: 1
        color:"lightgray"
    }

    Rectangle{
        y: rowHeight * 2 - 1
        x: rowHeight * 7 + nameWidth * 2 - 7
        height: rowHeight * 3
        width: 1
        color: "black"
    }

    Rectangle {
        id: thirdOne
        y: rowHeight * 9
        x: rowHeight * 4 + nameWidth * 2 - 5
        height: rowHeight
        width: rowHeight
        border.width: 1
        Text {
            text: drawThirdOne
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            padding: 4
        }
    }
    Rectangle{
        id: thirdOneResult
        y: rowHeight * 9
        x: rowHeight * 5 + nameWidth * 2 - 6
        height: rowHeight
        width: rowHeight * 2
        border.width: 1
        Rectangle{
            height: parent.height - 2
            width: parent.width / 2 - 2
            x: 1
            y: 1
            Text{
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                text: resultThird1SumBalls
            }
            //border.width: 1
        }
        Rectangle{
            height: parent.height - 2
            width: 1
            x: parent.width / 2
            y: 1
            color: "lightgray"
        }
        Rectangle{
            height: parent.height - 2
            width: parent.width / 2 - 2
            x: parent.width / 2 + 1
            y: 1
            Text{
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                text: resultThird1MaxRateCount
            }
        }
    }

    Rectangle {
        id: thirdTwo
        y: rowHeight * 11 - 2
        x: rowHeight * 4 + nameWidth * 2 - 5
        height: rowHeight
        width: rowHeight
        border.width: 1
        Text {
            text: drawThirdTwo
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            padding: 4
        }
    }
    Rectangle{
        id: thirdTwoResult
        y: rowHeight * 11 - 2
        x: rowHeight * 5 + nameWidth * 2 - 6
        height: rowHeight
        width: rowHeight * 2
        border.width: 1
        Rectangle{
            height: parent.height - 2
            width: parent.width / 2 - 2
            x: 1
            y: 1
            Text{
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                text: resultThird2SumBalls
            }
            //border.width: 1
        }
        Rectangle{
            height: parent.height - 2
            width: 1
            x: parent.width / 2
            y: 1
            color: "lightgray"
        }
        Rectangle{
            height: parent.height - 2
            width: parent.width / 2 - 2
            x: parent.width / 2 + 1
            y: 1
            Text{
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                text: resultThird2MaxRateCount
            }
        }
    }

    Rectangle{
        id: thirdStatus
        y: rowHeight * 10 - 1
        x: rowHeight * 6 + nameWidth * 2 - 6
        height: rowHeight
        width: rowHeight
        border.width: 1
        color:"lightgray"
    }

    Rectangle {
        id: firstPlace
        y: rowHeight * 3
        x: rowHeight * 7 + nameWidth * 2 - 7
        height: rowHeight
        width: rowHeight
        border.width: 1
        Text {
            text: placeOne
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            padding: 4
        }
    }

    Rectangle{
        y: rowHeight * 3
        x: rowHeight * 8 + nameWidth * 2 - 7
        height: rowHeight
        width: rowHeight
        Text {
            text: "1 место"
            anchors.verticalCenter: parent.verticalCenter
            padding: 4
        }
    }

    Rectangle {
        id: secondPlace
        y: rowHeight * 7
        x: rowHeight * 7 + nameWidth * 2 - 7
        height: rowHeight
        width: rowHeight
        border.width: 1
        Text {
            text: placeTwo
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            padding: 4
        }
    }

    Rectangle{
        y: rowHeight * 7
        x: rowHeight * 8 + nameWidth * 2 - 7
        height: rowHeight
        width: rowHeight
        Text {
            text: "2 место"
            anchors.verticalCenter: parent.verticalCenter
            padding: 4
        }
    }

    Rectangle {
        id: thirdPlace
        y: rowHeight * 10 - 1
        x: rowHeight * 7 + nameWidth * 2 - 7
        height: rowHeight
        width: rowHeight
        border.width: 1
        Text {
            text: placeThree
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            padding: 4
        }
    }

    Rectangle{
        y: rowHeight * 10 - 1
        x: rowHeight * 8 + nameWidth * 2 - 7
        height: rowHeight
        width: rowHeight
        Text {
            text: "3 место"
            anchors.verticalCenter: parent.verticalCenter
            padding: 4
        }
    }

}
