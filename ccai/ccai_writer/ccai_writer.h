/****************************************************************************************************
* File ccai_writer.c Start!
****************************************************************************************************/
#ifndef CCAI_WRITER_H
#define CCAI_WRITER_H

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "cc_type.h"
/* log */
#include "log.h"
#include "kernel_cfg.h"
/* sub module */

/* components */

/* ui */

/* cpp */
#include <QWidget>

/****************************************************************************************************
* Define
****************************************************************************************************/

/****************************************************************************************************
* Type Define
****************************************************************************************************/

/* cc_ccai_writer_workflow_enum */
typedef enum
{
    CC_CCAI_WRITER_WORKFLOW_FREE = 0,
    CC_CCAI_WRITER_WORKFLOW_1_INPUT_TITLE,
    CC_CCAI_WRITER_WORKFLOW_2_INPUT_USERCONTENT,
    CC_CCAI_WRITER_WORKFLOW_3_OPTIMIZE_CONTENT,
    CC_CCAI_WRITER_WORKFLOW_4_CONVERT_MARKDOWN,
    CC_CCAI_WRITER_WORKFLOW_5_CONVERT_XMIND,
    CC_CCAI_WRITER_WORKFLOW_6_DISPLAY_XMIND,
    CC_CCAI_WRITER_WORKFLOW_7_GENERATE_CREATE,
    CC_CCAI_WRITER_WORKFLOW_8_GENERATE_MARKDOWN,
    CC_CCAI_WRITER_WORKFLOW_9_RELEASE,
    CC_CCAI_WRITER_WORKFLOW_10_COMPLETE,
    CC_CCAI_WRITER_WORKFLOW_END,
}cc_ccai_writer_workflow_enum;

/* cc_ccai_writer_workflow_step4_struct */
typedef struct
{
    /* path */
    QString generatepath;
    /* cover */
    QString cover;
    /* catalogue */
    QString catalogue;
    /* header */
    QString header;
    /* footer */
    QString footer;
}cc_ccai_writer_workflow_step4_struct;

/* cc_ccai_writer_workflow_step7_struct */
typedef struct
{
    /* catalogue */
    QString catalogue;
    /* xmind */
    QString xmind;
    /* header */
    QString header;
    /* usercontent */
    QString usercontent;
    /* article */
    QString article;
    /* footer */
    QString footer;
}cc_ccai_writer_workflow_step7_struct;

/* cc_ccai_writer_workflow_struct */
typedef struct
{
    /* step 1 */
    QString step1_title;
    QString step1_content;
    /* step 2 */
    QString step2_usercontent;
    /* step 3 */
    QString step3_optimizecontent;
    /* step 4 */
    cc_ccai_writer_workflow_step4_struct step4;
    /* step 5 */
    QString step5_xmind_generatepath;
    /* step 6 */
    QString step6_optimizecontent;
    /* step 7 */
    cc_ccai_writer_workflow_step7_struct step7;
    /* step 8 */
    QString step8_markdown_generatepath;
    /* step 9 */
    QString step9_platform;
    /* step 10 */
    QString step10_end;
}cc_ccai_writer_workflow_struct;

/* cc_ccai_writer_struct */
typedef struct
{
    /* workflow */
    cc_ccai_writer_workflow_struct workflow;
    /* state */
    cc_ccai_writer_workflow_enum state;
    /* article */
    QString article;
}cc_ccai_writer_struct;

namespace Ui {
class CCAI_Writer;
}

class CCAI_Writer : public QWidget
{
    Q_OBJECT

public:
    explicit CCAI_Writer(QWidget *parent = nullptr);
    ~CCAI_Writer();
    /* state */
    cc_result cc_ccai_writer_enter_state(cc_ccai_writer_workflow_enum state);
    /* step */
    cc_result cc_ccai_writer_step1_to_step2(cc_void);
    cc_result cc_ccai_writer_step2_to_step3(cc_void);
    cc_result cc_ccai_writer_step3_to_step4(cc_void);
    cc_result cc_ccai_writer_step4_to_step5(cc_void);
    cc_result cc_ccai_writer_step5_to_step6(cc_void);
    cc_result cc_ccai_writer_step6_to_step7(cc_void);
    cc_result cc_ccai_writer_step7_to_step8(cc_void);
    cc_result cc_ccai_writer_step8_to_step9(cc_void);
    cc_result cc_ccai_writer_step9_to_step10(cc_void);

private slots:
    void on_pushButton_ccai_writer_1_confirm_clicked();
    void on_pushButton_ccai_writer_1_random_clicked();
    void on_pushButton_ccai_writer_2_confirm_clicked();
    void on_pushButton_ccai_writer_3_confirm_clicked();
    void on_pushButton_ccai_writer_4_confirm_clicked();
    void on_pushButton_ccai_writer_5_confirm_clicked();
    void on_pushButton_ccai_writer_6_confirm_clicked();
    void on_pushButton_ccai_writer_7_confirm_clicked();
    void on_pushButton_ccai_writer_8_confirm_clicked();
    void on_pushButton_ccai_writer_9_confirm_clicked();
    void on_pushButton_ccai_writer_10_confirm_clicked();
    void on_pushButton_ccai_writer_2_default_clicked();
    void on_pushButton_ccai_writer_3_regenerate_clicked();
    void on_pushButton_ccai_writer_3_open_clicked();
    void on_pushButton_ccai_writer_3_optimize_clicked();

    void on_pushButton_ccai_writer_4_base_path_clicked();

private:
    Ui::CCAI_Writer *ui;
    /* writer */
    cc_ccai_writer_struct writer;
};

/****************************************************************************************************
* Function Interface
****************************************************************************************************/
cc_result cc_ccai_writer_get_state(cc_ccai_writer_workflow_enum *state);
cc_result cc_ccai_writer_mainfunction(cc_void);

#endif // CCAI_WRITER_H
/****************************************************************************************************
* End file
****************************************************************************************************/
