
/****************************************************************************************************
* File file_pdf_pdfium.c Start!
****************************************************************************************************/

/*
 *
 *  Copyright (c) 2024-2025 by flechazo. All rights reserved.
 *
 * Author : CarlChai LinFeng Chai flechazo
 * Website: flechazo.mba
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-04-09     cc          the first version
 *
*/

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "file_pdf_pdfium.h"
/* log */
/* sub module */
/* components */

/* ui */
/* cpp */
#include <libloaderapi.h>

/****************************************************************************************************
* Define
****************************************************************************************************/

/****************************************************************************************************
* Type
****************************************************************************************************/

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/* cc_file_pdf_pdfium */
cc_file_pdf_pdfium_struct cc_file_pdf_pdfium_t;
/* init flag */
cc_boolean cc_file_pdf_pdfium_initflag = CC_FALSE;

/****************************************************************************************************
* Function Impletement
****************************************************************************************************/

/****************************************************************************************************
* cc_file_pdf_pdfium_init()
****************************************************************************************************/
cc_result cc_file_pdf_pdfium_init(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,cc_file_pdf_pdfium_initflag != CC_TRUE);
        /* init object */
        cc_file_pdf_pdfium_t.config.dpi = 72;

    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_file_pdf_pdfium_loaddll_func()
****************************************************************************************************/
cc_result cc_file_pdf_pdfium_loaddll_func(cc_file_pdf_pdfium_func_struct *func,HMODULE dllhandle)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,func);
        CHECK_PTR(result,dllhandle);
        /* impletement */
        func->FPDF_InitLibraryWithConfig = (void (*)(const FPDF_LIBRARY_CONFIG* config))GetProcAddress(dllhandle,"FPDF_InitLibraryWithConfig");
        func->FPDF_InitLibrary = (void (*)())GetProcAddress(dllhandle,"FPDF_InitLibrary");
        func->FPDF_DestroyLibrary = (void (*)())GetProcAddress(dllhandle,"FPDF_DestroyLibrary");
        func->FPDF_SetSandBoxPolicy = (void (*)(FPDF_DWORD policy,FPDF_BOOL enable))GetProcAddress(dllhandle,"FPDF_SetSandBoxPolicy");
        func->FPDF_SetPrintMode = (FPDF_BOOL (*)(int mode))GetProcAddress(dllhandle,"FPDF_SetPrintMode");
        func->FPDF_LoadDocument = (FPDF_DOCUMENT (*)(FPDF_STRING file_path, FPDF_BYTESTRING password))GetProcAddress(dllhandle,"FPDF_LoadDocument");
        func->FPDF_LoadMemDocument = (FPDF_DOCUMENT (*)(const void* data_buf, int size, FPDF_BYTESTRING password))GetProcAddress(dllhandle,"FPDF_LoadMemDocument");
        func->FPDF_LoadMemDocument64 = (FPDF_DOCUMENT (*)(const void* data_buf,size_t size,FPDF_BYTESTRING password))GetProcAddress(dllhandle,"FPDF_LoadMemDocument64");
        func->FPDF_LoadCustomDocument = (FPDF_DOCUMENT (*)(FPDF_FILEACCESS* pFileAccess, FPDF_BYTESTRING password))GetProcAddress(dllhandle,"FPDF_LoadCustomDocument");
        func->FPDF_GetFileVersion = (FPDF_BOOL (*)(FPDF_DOCUMENT doc,int* fileVersion))GetProcAddress(dllhandle,"FPDF_GetFileVersion");
        func->FPDF_GetLastError = (unsigned long (*)())GetProcAddress(dllhandle,"FPDF_GetLastError");
        func->FPDF_DocumentHasValidCrossReferenceTable = (FPDF_BOOL (*)(FPDF_DOCUMENT document))GetProcAddress(dllhandle,"FPDF_DocumentHasValidCrossReferenceTable");
        func->FPDF_GetTrailerEnds = (unsigned long (*)(FPDF_DOCUMENT document,unsigned int* buffer,unsigned long length))GetProcAddress(dllhandle,"FPDF_GetTrailerEnds");
        func->FPDF_GetDocPermissions = (unsigned long (*)(FPDF_DOCUMENT document))GetProcAddress(dllhandle,"FPDF_GetDocPermissions");
        func->FPDF_GetDocUserPermissions = (unsigned long (*)(FPDF_DOCUMENT document))GetProcAddress(dllhandle,"FPDF_GetDocUserPermissions");
        func->FPDF_GetSecurityHandlerRevision = (int (*)(FPDF_DOCUMENT document))GetProcAddress(dllhandle,"FPDF_GetSecurityHandlerRevision");
        func->FPDF_GetPageCount = (int (*)(FPDF_DOCUMENT document))GetProcAddress(dllhandle,"FPDF_GetPageCount");
        func->FPDF_LoadPage = (FPDF_PAGE (*)(FPDF_DOCUMENT document,int page_index))GetProcAddress(dllhandle,"FPDF_LoadPage");
        func->FPDF_GetPageWidthF = (float (*)(FPDF_PAGE page))GetProcAddress(dllhandle,"FPDF_GetPageWidthF");
        func->FPDF_GetPageWidth = (double (*)(FPDF_PAGE page))GetProcAddress(dllhandle,"FPDF_GetPageWidth");
        func->FPDF_GetPageHeightF = (float (*)(FPDF_PAGE page))GetProcAddress(dllhandle,"FPDF_GetPageHeightF");
        func->FPDF_GetPageHeight = (double (*)(FPDF_PAGE page))GetProcAddress(dllhandle,"FPDF_GetPageHeight");
        func->FPDF_GetPageBoundingBox = (FPDF_BOOL (*)(FPDF_PAGE page,FS_RECTF* rect))GetProcAddress(dllhandle,"FPDF_GetPageBoundingBox");
        func->FPDF_GetPageSizeByIndexF = (FPDF_BOOL (*)(FPDF_DOCUMENT document,int page_index,FS_SIZEF* size))GetProcAddress(dllhandle,"FPDF_GetPageSizeByIndexF");
        func->FPDF_GetPageSizeByIndex = (int (*)(FPDF_DOCUMENT document,int page_index,double* width,double* height))GetProcAddress(dllhandle,"FPDF_GetPageSizeByIndex");
        func->FPDF_RenderPageBitmap = (void (*)(FPDF_BITMAP bitmap,FPDF_PAGE page,int start_x,int start_y,int size_x,int size_y,int rotate,int flags))GetProcAddress(dllhandle,"FPDF_RenderPageBitmap");
        func->FPDF_RenderPageBitmapWithMatrix = (void (*)(FPDF_BITMAP bitmap,FPDF_PAGE page,const FS_MATRIX* matrix,const FS_RECTF* clipping,int flags))GetProcAddress(dllhandle,"FPDF_RenderPageBitmapWithMatrix");
        func->FPDF_RenderPageSkia = (void (*)(FPDF_SKIA_CANVAS canvas,FPDF_PAGE page,int size_x,int size_y))GetProcAddress(dllhandle,"FPDF_RenderPageSkia");
        func->FPDF_ClosePage = (void (*)(FPDF_PAGE page))GetProcAddress(dllhandle,"FPDF_ClosePage");
        func->FPDF_CloseDocument = (void (*)(FPDF_DOCUMENT document))GetProcAddress(dllhandle,"FPDF_CloseDocument");
        func->FPDF_DeviceToPage = (FPDF_BOOL (*)(FPDF_PAGE page,int start_x,int start_y,int size_x,int size_y,int rotate,int device_x,int device_y,double* page_x,double* page_y))GetProcAddress(dllhandle,"FPDF_DeviceToPage");
        func->FPDF_PageToDevice = (FPDF_BOOL (*)(FPDF_PAGE page,int start_x,int start_y,int size_x,int size_y,int rotate,double page_x,double page_y,int* device_x,int* device_y))GetProcAddress(dllhandle,"FPDF_PageToDevice");
        func->FPDFBitmap_Create = (FPDF_BITMAP (*)(int width,int height,int alpha))GetProcAddress(dllhandle,"FPDFBitmap_Create");
        func->FPDFBitmap_CreateEx = (FPDF_BITMAP (*)(int width,int height,int format,void* first_scan,int stride))GetProcAddress(dllhandle,"FPDFBitmap_CreateEx");
        func->FPDFBitmap_GetFormat = (int (*)(FPDF_BITMAP bitmap))GetProcAddress(dllhandle,"FPDFBitmap_GetFormat");
        func->FPDFBitmap_FillRect = (FPDF_BOOL (*)(FPDF_BITMAP bitmap,int left,int top,int width,int height,FPDF_DWORD color))GetProcAddress(dllhandle,"FPDFBitmap_FillRect");
        func->FPDFBitmap_GetBuffer = (void* (*)(FPDF_BITMAP bitmap))GetProcAddress(dllhandle,"FPDFBitmap_GetBuffer");
        func->FPDFBitmap_GetWidth = (int (*)(FPDF_BITMAP bitmap))GetProcAddress(dllhandle,"FPDFBitmap_GetWidth");
        func->FPDFBitmap_GetHeight = (int (*)(FPDF_BITMAP bitmap))GetProcAddress(dllhandle,"FPDFBitmap_GetHeight");
        func->FPDFBitmap_GetStride = (int (*)(FPDF_BITMAP bitmap))GetProcAddress(dllhandle,"FPDFBitmap_GetStride");
        func->FPDFBitmap_Destroy = (int (*)(FPDF_BITMAP bitmap))GetProcAddress(dllhandle,"FPDFBitmap_Destroy");
        func->FPDF_VIEWERREF_GetPrintScaling = (FPDF_BOOL (*)(FPDF_DOCUMENT document))GetProcAddress(dllhandle,"FPDF_VIEWERREF_GetPrintScaling");
        func->FPDF_VIEWERREF_GetNumCopies = (int (*)(FPDF_DOCUMENT document))GetProcAddress(dllhandle,"FPDF_VIEWERREF_GetNumCopies");
        func->FPDF_VIEWERREF_GetPrintPageRange = (FPDF_PAGERANGE (*)(FPDF_DOCUMENT document))GetProcAddress(dllhandle,"FPDF_VIEWERREF_GetPrintPageRange");
        func->FPDF_VIEWERREF_GetPrintPageRangeCount = (size_t (*)(FPDF_PAGERANGE pagerange))GetProcAddress(dllhandle,"FPDF_VIEWERREF_GetPrintPageRangeCount");
        func->FPDF_VIEWERREF_GetPrintPageRangeElement = (int (*)(FPDF_PAGERANGE pagerange, size_t index))GetProcAddress(dllhandle,"FPDF_VIEWERREF_GetPrintPageRangeElement");
        func->FPDF_VIEWERREF_GetDuplex = (FPDF_DUPLEXTYPE (*)(FPDF_DOCUMENT document))GetProcAddress(dllhandle,"FPDF_VIEWERREF_GetDuplex");
        func->FPDF_VIEWERREF_GetName = (unsigned long (*)(FPDF_DOCUMENT document,FPDF_BYTESTRING key,char* buffer,unsigned long length))GetProcAddress(dllhandle,"FPDF_VIEWERREF_GetName");
        func->FPDF_CountNamedDests = (FPDF_DWORD (*)(FPDF_DOCUMENT document))GetProcAddress(dllhandle,"FPDF_CountNamedDests");
        func->FPDF_GetNamedDestByName = (FPDF_DEST (*)(FPDF_DOCUMENT document, FPDF_BYTESTRING name))GetProcAddress(dllhandle,"FPDF_GetNamedDestByName");
        func->FPDF_GetNamedDest = (FPDF_DEST (*)(FPDF_DOCUMENT document,int index,void* buffer,long* buflen))GetProcAddress(dllhandle,"FPDF_GetNamedDest");
        func->FPDF_GetXFAPacketCount = (int (*)(FPDF_DOCUMENT document))GetProcAddress(dllhandle,"FPDF_GetXFAPacketCount");
        func->FPDF_GetXFAPacketName = (unsigned long (*)(FPDF_DOCUMENT document,int index,void* buffer,unsigned long buflen))GetProcAddress(dllhandle,"FPDF_GetXFAPacketName");
        func->FPDF_GetXFAPacketContent = (FPDF_BOOL (*)(FPDF_DOCUMENT document,int index,void* buffer,unsigned long buflen,unsigned long* out_buflen))GetProcAddress(dllhandle,"FPDF_GetXFAPacketContent");
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_file_pdf_pdfium_loaddll()
****************************************************************************************************/
cc_result cc_file_pdf_pdfium_loaddll(QString filepath)
{
    cc_result result = CC_E_OK;
    QByteArray qbytearray;

    do
    {
        /* check */
        CHECK_LOGIC(result,(filepath != ""));
        CHECK_LOGIC(result,cc_file_pdf_pdfium_t.dllhandle == CC_NULL_PTR);
        CHECK_LOGIC(result,(filepath.contains(".dll") == CC_TRUE));
        CHECK_LOGIC(result,(QFile::exists(filepath) == CC_TRUE));
        /* load */
        qbytearray = filepath.toUtf8();
        cc_file_pdf_pdfium_t.dllhandle = LoadLibraryA(qbytearray.constData());
        CHECK_PTR(result,cc_file_pdf_pdfium_t.dllhandle);
        /* init func */
        cc_file_pdf_pdfium_loaddll_func(&cc_file_pdf_pdfium_t.func,(HMODULE)cc_file_pdf_pdfium_t.dllhandle);
        /* init pdfium */
        CHECK_PTR(result,cc_file_pdf_pdfium_t.func.FPDF_InitLibrary);
        cc_file_pdf_pdfium_t.func.FPDF_InitLibrary();
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_file_pdf_pdfium_unloaddll()
****************************************************************************************************/
cc_result cc_file_pdf_pdfium_unloaddll(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,cc_file_pdf_pdfium_t.func.FPDF_DestroyLibrary);
        /* destroy pdfium */
        cc_file_pdf_pdfium_t.func.FPDF_DestroyLibrary();
        /* free dll */
        CHECK_PTR(result,cc_file_pdf_pdfium_t.dllhandle);
        FreeLibrary((HMODULE)cc_file_pdf_pdfium_t.dllhandle);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_file_pdf_pdfium_readinfo()
****************************************************************************************************/
cc_result cc_file_pdf_pdfium_readinfo(QString pdfpath)
{
    cc_result result = CC_E_OK;

    do
    {

    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_file_pdf_pdfium_convert_img_to_pdf()
****************************************************************************************************/
cc_result cc_file_pdf_pdfium_convert_img_to_pdf()
{
    cc_result result = CC_E_OK;

    do
    {

    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_file_pdf_pdfium_convert_bitmap_to_qimage()
****************************************************************************************************/
cc_result cc_file_pdf_pdfium_convert_bitmap_to_qimage(QImage *image,FPDF_BITMAP bitmap)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,image);
        CHECK_PTR(result,bitmap);
        /* impletement */
        int width = cc_file_pdf_pdfium_t.func.FPDFBitmap_GetWidth(bitmap);
        int height = cc_file_pdf_pdfium_t.func.FPDFBitmap_GetHeight(bitmap);
        void* buffer = cc_file_pdf_pdfium_t.func.FPDFBitmap_GetBuffer(bitmap);
        int stride = cc_file_pdf_pdfium_t.func.FPDFBitmap_GetStride(bitmap);

        // PDFium BGRA -> QImage ARGB
        QImage qimage(static_cast<uchar*>(buffer), width, height, stride, QImage::Format_ARGB32);
        /* output */
        *image = qimage.rgbSwapped();
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_file_pdf_pdfium_convert_pdf_to_img_process_page()
****************************************************************************************************/
cc_result cc_file_pdf_pdfium_convert_pdf_to_img_process_page(FPDF_PAGE page,QList<QImage> *images)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,page);
        CHECK_PTR(result,images);

        /* impletement */
        /* get width & height */
        double width = cc_file_pdf_pdfium_t.func.FPDF_GetPageWidth(page);
        double height = cc_file_pdf_pdfium_t.func.FPDF_GetPageHeight(page);
        /* dpi */
        int scaledWidth = static_cast<int>(width * cc_file_pdf_pdfium_t.config.dpi / 72);
        int scaledHeight = static_cast<int>(height * cc_file_pdf_pdfium_t.config.dpi / 72);
        /* bitmap */
        FPDF_BITMAP bitmap = cc_file_pdf_pdfium_t.func.FPDFBitmap_Create(scaledWidth, scaledHeight, 0);
        CHECK_PTR(result,bitmap);
        /* fill background */
        cc_file_pdf_pdfium_t.func.FPDFBitmap_FillRect(bitmap, 0, 0, scaledWidth, scaledHeight, 0xFFFFFFFF);
        /* page -> bitmap */
        cc_file_pdf_pdfium_t.func.FPDF_RenderPageBitmap(bitmap, page, 0, 0, scaledWidth, scaledHeight, 0, FPDF_ANNOT);
        /* bitmap -> QImage */
        QImage image;
        cc_file_pdf_pdfium_convert_bitmap_to_qimage(&image,bitmap);
        images->append(image);
        /* release */
        cc_file_pdf_pdfium_t.func.FPDFBitmap_Destroy(bitmap);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_file_pdf_pdfium_convert_pdf_to_img_process_pdf()
****************************************************************************************************/
cc_result cc_file_pdf_pdfium_convert_pdf_to_img_process_pdf(FPDF_DOCUMENT pdf,QList<QImage> *images)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,pdf);
        CHECK_PTR(result,images);

        /* impletement */
        /* page count */
        int pagecount = cc_file_pdf_pdfium_t.func.FPDF_GetPageCount(pdf);
        for (int i = 0; i < pagecount; ++i)
        {
            /* page */
            FPDF_PAGE page = cc_file_pdf_pdfium_t.func.FPDF_LoadPage(pdf, i);
            CHECK_PTR(result,page);
            /* process */
            cc_file_pdf_pdfium_convert_pdf_to_img_process_page(page,images);
            /* close page */
            cc_file_pdf_pdfium_t.func.FPDF_ClosePage(page);
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_file_pdf_pdfium_convert_pdf_to_img()
****************************************************************************************************/
cc_result cc_file_pdf_pdfium_convert_pdf_to_img(QString pdfpath,QList<QImage> *images)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,images);
        CHECK_LOGIC(result,(pdfpath != ""));
        CHECK_LOGIC(result,cc_file_pdf_pdfium_t.dllhandle != CC_NULL_PTR);
        CHECK_LOGIC(result,(pdfpath.contains(".pdf") == CC_TRUE));
        CHECK_LOGIC(result,(QFile::exists(pdfpath) == CC_TRUE));
        /* impletement */
        /* load */
        cc_file_pdf_pdfium_t.pdf = cc_file_pdf_pdfium_t.func.FPDF_LoadDocument(pdfpath.toStdString().c_str(),nullptr);
        CHECK_PTR(result,cc_file_pdf_pdfium_t.pdf);
        /* process */
        cc_file_pdf_pdfium_convert_pdf_to_img_process_pdf(cc_file_pdf_pdfium_t.pdf,images);
        /* close pdf */
        cc_file_pdf_pdfium_t.func.FPDF_CloseDocument(cc_file_pdf_pdfium_t.pdf);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_file_pdf_pdfium_output_qimage_to_img()
****************************************************************************************************/
cc_result cc_file_pdf_pdfium_output_qimage_to_img(QImage *image,QString imgpath)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,image);
        CHECK_LOGIC(result,(imgpath != ""));
        /* save */
        image->save(imgpath,"PNG",95);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_file_pdf_pdfium_output_img()
****************************************************************************************************/
cc_result cc_file_pdf_pdfium_output_img(QList<QImage> *images,QString directory)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,images);
        CHECK_LOGIC(result,(directory != ""));
        /* impletement */
        for (int i = 0; i < images->size(); ++i)
        {
            /* imgpath */
            QString imgpath = directory + "/" + QString("page_%1.png").arg(i + 1);
            /* qimage */
            QImage image = images->at(i);
            /* save */
            cc_file_pdf_pdfium_output_qimage_to_img(&image,imgpath);
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_file_pdf_pdfium_mainfunction()
****************************************************************************************************/
cc_result cc_file_pdf_pdfium_mainfunction(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {

    }while(0u);

    return result;
}

/****************************************************************************************************
* File file_pdf_pdfium.c End!
****************************************************************************************************/

