#ifndef MAPPINGDATA_H
#define MAPPINGDATA_H
#include <qglobal.h>
#include <QString>
#include <QColor>

typedef struct _MappingDataStruct
{

    int flat_notch;//平口或缺口
    //top - 0 left - 90 bottom - 180 right - 270
    int flat_notch_angle;//缺口朝向
    int pos_ori_loc;//原点方位0 左上角，1左下角，2右下角，3右上角

    QString wafer_id;
    QString product_id;
    QString date;
    QString dist_unit;

    double device_width;
    double device_height;

    int wafer_size;
    int total_dies;
    int good_dies;
    int rows;
    int cols;
    int ref_col;
    int ref_row;

    double x_step;
    double y_step;

    double ref_x;
    double ref_y;

    double center_x;
    double center_y;
public:
    _MappingDataStruct() {
        flat_notch = 0;//平口
        flat_notch_angle = 0;
        pos_ori_loc = 0;//左上角
        wafer_id = "A2801";
        product_id = "GL01";
        date = "2023/01/01";
        dist_unit = "mm";
        wafer_size = 150;
        device_width = 3.5;
        device_height = 2.5;

        x_step = 3.8;
        y_step = 2.8;

        total_dies = 0;
        good_dies = 0;
        rows = 52;
        cols = 38;
        ref_x = -70.3;
        ref_y = -71.4;
        ref_row = 0;
        ref_col = 0;
        center_x = 0;
        center_y = 0;
    }
}MappingDataStruct;

typedef struct _MappingStyle
{
    //QColor sceneBackColor = "#171B24";
    QColor die_hintColor = "#C9FF00";
    QColor die_okColor = "#418022";//ok 颜色
    QColor die_ngColor = "#B22512";//ng 颜色
    QColor die_checkableColor = "#E5A884";//可检颜色
    QColor die_checkColor = "#819ED6";//待检颜色
    QColor die_substribeColor = "#6F8792";//基板颜色
    QColor die_nullColor = "#344C74";
    QColor die_refColor = "#1AA6F6";
    QColor die_markColor = "#512F20";
} MappingStyle;

#endif // MAPPINGDATA_H
