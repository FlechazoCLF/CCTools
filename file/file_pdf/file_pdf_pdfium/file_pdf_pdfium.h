
/****************************************************************************************************
* File file_pdf_pdfium.h Start!
****************************************************************************************************/

#ifndef _FILE_PDF_PDFIUM_H
#define _FILE_PDF_PDFIUM_H

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "cc_type.h"
/* log */
/* sub module */
#include "file_pdf_pdfium_cfg.h"
/* components */

/* ui */
/* cpp */
#include <QString>
#include <QFile>
#include <QImage>

/****************************************************************************************************
* Define
****************************************************************************************************/

/****************************************************************************************************
* Type
****************************************************************************************************/


/* cc_file_pdf_pdfium_func_struct */
typedef struct
{
    void (*FPDF_InitLibraryWithConfig)(const FPDF_LIBRARY_CONFIG* config);
    void (*FPDF_InitLibrary)();
    void (*FPDF_DestroyLibrary)();
    void (*FPDF_SetSandBoxPolicy)(FPDF_DWORD policy,FPDF_BOOL enable);
    FPDF_BOOL (*FPDF_SetPrintMode)(int mode);
    FPDF_DOCUMENT (*FPDF_LoadDocument)(FPDF_STRING file_path, FPDF_BYTESTRING password);
    FPDF_DOCUMENT (*FPDF_LoadMemDocument)(const void* data_buf, int size, FPDF_BYTESTRING password);
    FPDF_DOCUMENT (*FPDF_LoadMemDocument64)(const void* data_buf,size_t size,FPDF_BYTESTRING password);
    FPDF_DOCUMENT (*FPDF_LoadCustomDocument)(FPDF_FILEACCESS* pFileAccess, FPDF_BYTESTRING password);
    FPDF_BOOL (*FPDF_GetFileVersion)(FPDF_DOCUMENT doc,int* fileVersion);
    unsigned long (*FPDF_GetLastError)();
    FPDF_BOOL (*FPDF_DocumentHasValidCrossReferenceTable)(FPDF_DOCUMENT document);
    unsigned long (*FPDF_GetTrailerEnds)(FPDF_DOCUMENT document,unsigned int* buffer,unsigned long length);
    unsigned long (*FPDF_GetDocPermissions)(FPDF_DOCUMENT document);
    unsigned long (*FPDF_GetDocUserPermissions)(FPDF_DOCUMENT document);
    int (*FPDF_GetSecurityHandlerRevision)(FPDF_DOCUMENT document);
    int (*FPDF_GetPageCount)(FPDF_DOCUMENT document);
    FPDF_PAGE (*FPDF_LoadPage)(FPDF_DOCUMENT document,int page_index);
    float (*FPDF_GetPageWidthF)(FPDF_PAGE page);
    double (*FPDF_GetPageWidth)(FPDF_PAGE page);
    float (*FPDF_GetPageHeightF)(FPDF_PAGE page);
    double (*FPDF_GetPageHeight)(FPDF_PAGE page);
    FPDF_BOOL (*FPDF_GetPageBoundingBox)(FPDF_PAGE page,FS_RECTF* rect);
    FPDF_BOOL (*FPDF_GetPageSizeByIndexF)(FPDF_DOCUMENT document,int page_index,FS_SIZEF* size);
    int (*FPDF_GetPageSizeByIndex)(FPDF_DOCUMENT document,int page_index,double* width,double* height);
    void (*FPDF_RenderPageBitmap)(FPDF_BITMAP bitmap,FPDF_PAGE page,int start_x,int start_y,int size_x,int size_y,int rotate,int flags);
    void (*FPDF_RenderPageBitmapWithMatrix)(FPDF_BITMAP bitmap,FPDF_PAGE page,const FS_MATRIX* matrix,const FS_RECTF* clipping,int flags);
    void (*FPDF_RenderPageSkia)(FPDF_SKIA_CANVAS canvas,FPDF_PAGE page,int size_x,int size_y);
    void (*FPDF_ClosePage)(FPDF_PAGE page);
    void (*FPDF_CloseDocument)(FPDF_DOCUMENT document);
    FPDF_BOOL (*FPDF_DeviceToPage)(FPDF_PAGE page,int start_x,int start_y,int size_x,int size_y,int rotate,int device_x,int device_y,double* page_x,double* page_y);
    FPDF_BOOL (*FPDF_PageToDevice)(FPDF_PAGE page,int start_x,int start_y,int size_x,int size_y,int rotate,double page_x,double page_y,int* device_x,int* device_y);
    FPDF_BITMAP (*FPDFBitmap_Create)(int width,int height,int alpha);
    FPDF_BITMAP (*FPDFBitmap_CreateEx)(int width,int height,int format,void* first_scan,int stride);
    int (*FPDFBitmap_GetFormat)(FPDF_BITMAP bitmap);
    FPDF_BOOL (*FPDFBitmap_FillRect)(FPDF_BITMAP bitmap,int left,int top,int width,int height,FPDF_DWORD color);
    void* (*FPDFBitmap_GetBuffer)(FPDF_BITMAP bitmap);
    int (*FPDFBitmap_GetWidth)(FPDF_BITMAP bitmap);
    int (*FPDFBitmap_GetHeight)(FPDF_BITMAP bitmap);
    int (*FPDFBitmap_GetStride)(FPDF_BITMAP bitmap);
    int (*FPDFBitmap_Destroy)(FPDF_BITMAP bitmap);
    FPDF_BOOL (*FPDF_VIEWERREF_GetPrintScaling)(FPDF_DOCUMENT document);
    int (*FPDF_VIEWERREF_GetNumCopies)(FPDF_DOCUMENT document);
    FPDF_PAGERANGE (*FPDF_VIEWERREF_GetPrintPageRange)(FPDF_DOCUMENT document);
    size_t (*FPDF_VIEWERREF_GetPrintPageRangeCount)(FPDF_PAGERANGE pagerange);
    int (*FPDF_VIEWERREF_GetPrintPageRangeElement)(FPDF_PAGERANGE pagerange, size_t index);
    FPDF_DUPLEXTYPE (*FPDF_VIEWERREF_GetDuplex)(FPDF_DOCUMENT document);
    unsigned long (*FPDF_VIEWERREF_GetName)(FPDF_DOCUMENT document,FPDF_BYTESTRING key,char* buffer,unsigned long length);
    FPDF_DWORD (*FPDF_CountNamedDests)(FPDF_DOCUMENT document);
    FPDF_DEST (*FPDF_GetNamedDestByName)(FPDF_DOCUMENT document, FPDF_BYTESTRING name);
    FPDF_DEST (*FPDF_GetNamedDest)(FPDF_DOCUMENT document,int index,void* buffer,long* buflen);
    int (*FPDF_GetXFAPacketCount)(FPDF_DOCUMENT document);
    unsigned long (*FPDF_GetXFAPacketName)(FPDF_DOCUMENT document,int index,void* buffer,unsigned long buflen);
    FPDF_BOOL (*FPDF_GetXFAPacketContent)(FPDF_DOCUMENT document,int index,void* buffer,unsigned long buflen,unsigned long* out_buflen);
}cc_file_pdf_pdfium_func_struct;

/* cc_file_pdf_pdfium_config_struct */
typedef struct
{
    QString page;
    cc_uint32 dpi;
    QString color;
    cc_uint32 rotate;
    cc_boolean antialiasing;
    cc_uint32 transparency;
    double scale;
    cc_boolean limit;
    cc_uint32 limitwidth;
    cc_uint32 limitheigth;
}cc_file_pdf_pdfium_config_struct;

/* cc_file_pdf_pdfium */
typedef struct
{
    cc_uint8 id;
    /* dll */
    void *dllhandle;
    /* pdfium func */
    cc_file_pdf_pdfium_func_struct func;
    /* user config */
    cc_file_pdf_pdfium_config_struct config;
    /* doc */
    FPDF_DOCUMENT pdf;
}cc_file_pdf_pdfium_struct;

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/****************************************************************************************************
* Function
****************************************************************************************************/

cc_result cc_file_pdf_pdfium_init(cc_void);
cc_result cc_file_pdf_pdfium_loaddll(QString filepath);
cc_result cc_file_pdf_pdfium_unloaddll(cc_void);
cc_result cc_file_pdf_pdfium_convert_pdf_to_img(QString pdfpath,QList<QImage> *images);
cc_result cc_file_pdf_pdfium_output_img(QList<QImage> *images,QString directory);
cc_result cc_file_pdf_pdfium_mainfunction(cc_void);

#endif /* _FILE_PDF_PDFIUM_H */
/****************************************************************************************************
* File file_pdf_pdfium.h End!
****************************************************************************************************/

