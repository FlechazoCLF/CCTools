
/****************************************************************************************************
* File file_pdf_pdfium_cfg.h Start!
****************************************************************************************************/

#ifndef _FILE_PDF_PDFIUM_CFG_H
#define _FILE_PDF_PDFIUM_CFG_H

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "cc_type.h"
/* log */
/* sub module */
/* components */

/* ui */
/* cpp */

/****************************************************************************************************
* Define
****************************************************************************************************/

// PDF object types
#define FPDF_OBJECT_UNKNOWN 0
#define FPDF_OBJECT_BOOLEAN 1
#define FPDF_OBJECT_NUMBER 2
#define FPDF_OBJECT_STRING 3
#define FPDF_OBJECT_NAME 4
#define FPDF_OBJECT_ARRAY 5
#define FPDF_OBJECT_DICTIONARY 6
#define FPDF_OBJECT_STREAM 7
#define FPDF_OBJECT_NULLOBJ 8
#define FPDF_OBJECT_REFERENCE 9

/****************************************************************************************************
* Type
****************************************************************************************************/

// PDF text rendering modes
typedef enum {
    FPDF_TEXTRENDERMODE_UNKNOWN = -1,
    FPDF_TEXTRENDERMODE_FILL = 0,
    FPDF_TEXTRENDERMODE_STROKE = 1,
    FPDF_TEXTRENDERMODE_FILL_STROKE = 2,
    FPDF_TEXTRENDERMODE_INVISIBLE = 3,
    FPDF_TEXTRENDERMODE_FILL_CLIP = 4,
    FPDF_TEXTRENDERMODE_STROKE_CLIP = 5,
    FPDF_TEXTRENDERMODE_FILL_STROKE_CLIP = 6,
    FPDF_TEXTRENDERMODE_CLIP = 7,
    FPDF_TEXTRENDERMODE_LAST = FPDF_TEXTRENDERMODE_CLIP,
} FPDF_TEXT_RENDERMODE;

// PDF types - use incomplete types (never completed) to force API type safety.
typedef struct fpdf_action_t__* FPDF_ACTION;
typedef struct fpdf_annotation_t__* FPDF_ANNOTATION;
typedef struct fpdf_attachment_t__* FPDF_ATTACHMENT;
typedef struct fpdf_avail_t__* FPDF_AVAIL;
typedef struct fpdf_bitmap_t__* FPDF_BITMAP;
typedef struct fpdf_bookmark_t__* FPDF_BOOKMARK;
typedef struct fpdf_clippath_t__* FPDF_CLIPPATH;
typedef struct fpdf_dest_t__* FPDF_DEST;
typedef struct fpdf_document_t__* FPDF_DOCUMENT;
typedef struct fpdf_font_t__* FPDF_FONT;
typedef struct fpdf_form_handle_t__* FPDF_FORMHANDLE;
typedef const struct fpdf_glyphpath_t__* FPDF_GLYPHPATH;
typedef struct fpdf_javascript_action_t* FPDF_JAVASCRIPT_ACTION;
typedef struct fpdf_link_t__* FPDF_LINK;
typedef struct fpdf_page_t__* FPDF_PAGE;
typedef struct fpdf_pagelink_t__* FPDF_PAGELINK;
typedef struct fpdf_pageobject_t__* FPDF_PAGEOBJECT;  // (text, path, etc.)
typedef struct fpdf_pageobjectmark_t__* FPDF_PAGEOBJECTMARK;
typedef const struct fpdf_pagerange_t__* FPDF_PAGERANGE;
typedef const struct fpdf_pathsegment_t* FPDF_PATHSEGMENT;
typedef struct fpdf_schhandle_t__* FPDF_SCHHANDLE;
typedef const struct fpdf_signature_t__* FPDF_SIGNATURE;
typedef void* FPDF_SKIA_CANVAS;  // Passed into Skia as an SkCanvas.
typedef struct fpdf_structelement_t__* FPDF_STRUCTELEMENT;
typedef const struct fpdf_structelement_attr_t__* FPDF_STRUCTELEMENT_ATTR;
typedef const struct fpdf_structelement_attr_value_t__* FPDF_STRUCTELEMENT_ATTR_VALUE;
typedef struct fpdf_structtree_t__* FPDF_STRUCTTREE;
typedef struct fpdf_textpage_t__* FPDF_TEXTPAGE;
typedef struct fpdf_widget_t__* FPDF_WIDGET;
typedef struct fpdf_xobject_t__* FPDF_XOBJECT;

// Basic data types
typedef int FPDF_BOOL;
typedef int FPDF_RESULT;
typedef unsigned long FPDF_DWORD;
typedef float FS_FLOAT;

// Duplex types
typedef enum _FPDF_DUPLEXTYPE_ {
    DuplexUndefined = 0,
    Simplex,
    DuplexFlipShortEdge,
    DuplexFlipLongEdge
} FPDF_DUPLEXTYPE;

// PDF renderer types - Experimental.
// Selection of 2D graphics library to use for rendering to FPDF_BITMAPs.
typedef enum {
    // Anti-Grain Geometry - https://sourceforge.net/projects/agg/
    FPDF_RENDERERTYPE_AGG = 0,
    // Skia - https://skia.org/
    FPDF_RENDERERTYPE_SKIA = 1,
} FPDF_RENDERER_TYPE;

// String types
typedef unsigned short FPDF_WCHAR;

// The public PDFium API uses three types of strings: byte string, wide string
// (UTF-16LE encoded), and platform dependent string.

// Public PDFium API type for byte strings.
typedef const char* FPDF_BYTESTRING;

// The public PDFium API always uses UTF-16LE encoded wide strings, each
// character uses 2 bytes (except surrogation), with the low byte first.
typedef const FPDF_WCHAR* FPDF_WIDESTRING;

// Structure for persisting a string beyond the duration of a callback.
// Note: although represented as a char*, string may be interpreted as
// a UTF-16LE formated string. Used only by XFA callbacks.
typedef struct FPDF_BSTR_ {
    char* str;  // String buffer, manipulate only with FPDF_BStr_* methods.
    int len;    // Length of the string, in bytes.
} FPDF_BSTR;

// For Windows programmers: In most cases it's OK to treat FPDF_WIDESTRING as a
// Windows unicode string, however, special care needs to be taken if you
// expect to process Unicode larger than 0xffff.
//
// For Linux/Unix programmers: most compiler/library environments use 4 bytes
// for a Unicode character, and you have to convert between FPDF_WIDESTRING and
// system wide string by yourself.
typedef const char* FPDF_STRING;

// Matrix for transformation, in the form [a b c d e f], equivalent to:
// | a  b  0 |
// | c  d  0 |
// | e  f  1 |
//
// Translation is performed with [1 0 0 1 tx ty].
// Scaling is performed with [sx 0 0 sy 0 0].
// See PDF Reference 1.7, 4.2.2 Common Transformations for more.
typedef struct _FS_MATRIX_ {
    float a;
    float b;
    float c;
    float d;
    float e;
    float f;
} FS_MATRIX;

// Rectangle area(float) in device or page coordinate system.
typedef struct _FS_RECTF_ {
    // The x-coordinate of the left-top corner.
    float left;
    // The y-coordinate of the left-top corner.
    float top;
    // The x-coordinate of the right-bottom corner.
    float right;
    // The y-coordinate of the right-bottom corner.
    float bottom;
} * FS_LPRECTF, FS_RECTF;

// Const Pointer to FS_RECTF structure.
typedef const FS_RECTF* FS_LPCRECTF;

// Rectangle size. Coordinate system agnostic.
typedef struct FS_SIZEF_ {
    float width;
    float height;
} * FS_LPSIZEF, FS_SIZEF;

// Const Pointer to FS_SIZEF structure.
typedef const FS_SIZEF* FS_LPCSIZEF;

// 2D Point. Coordinate system agnostic.
typedef struct FS_POINTF_ {
    float x;
    float y;
} * FS_LPPOINTF, FS_POINTF;

// Const Pointer to FS_POINTF structure.
typedef const FS_POINTF* FS_LPCPOINTF;

typedef struct _FS_QUADPOINTSF {
    FS_FLOAT x1;
    FS_FLOAT y1;
    FS_FLOAT x2;
    FS_FLOAT y2;
    FS_FLOAT x3;
    FS_FLOAT y3;
    FS_FLOAT x4;
    FS_FLOAT y4;
} FS_QUADPOINTSF;

// Annotation enums.
typedef int FPDF_ANNOTATION_SUBTYPE;
typedef int FPDF_ANNOT_APPEARANCEMODE;

// Dictionary value types.
typedef int FPDF_OBJECT_TYPE;

// Process-wide options for initializing the library.
typedef struct FPDF_LIBRARY_CONFIG_ {
    // Version number of the interface. Currently must be 2.
    // Support for version 1 will be deprecated in the future.
    int version;

    // Array of paths to scan in place of the defaults when using built-in
    // FXGE font loading code. The array is terminated by a NULL pointer.
    // The Array may be NULL itself to use the default paths. May be ignored
    // entirely depending upon the platform.
    const char** m_pUserFontPaths;

    // Version 2.

    // Pointer to the v8::Isolate to use, or NULL to force PDFium to create one.
    void* m_pIsolate;

    // The embedder data slot to use in the v8::Isolate to store PDFium's
    // per-isolate data. The value needs to be in the range
    // [0, |v8::Internals::kNumIsolateDataLots|). Note that 0 is fine for most
    // embedders.
    unsigned int m_v8EmbedderSlot;

    // Version 3 - Experimental.

    // Pointer to the V8::Platform to use.
    void* m_pPlatform;

    // Version 4 - Experimental.

    // Explicit specification of core renderer to use. |m_RendererType| must be
    // a valid value for |FPDF_LIBRARY_CONFIG| versions of this level or higher,
    // or else the initialization will fail with an immediate crash.
    // Note that use of a specified |FPDF_RENDERER_TYPE| value for which the
    // corresponding render library is not included in the build will similarly
    // fail with an immediate crash.
    FPDF_RENDERER_TYPE m_RendererType;
} FPDF_LIBRARY_CONFIG;

// Structure for custom file access.
typedef struct {
    // File length, in bytes.
    unsigned long m_FileLen;

    // A function pointer for getting a block of data from a specific position.
    // Position is specified by byte offset from the beginning of the file.
    // The pointer to the buffer is never NULL and the size is never 0.
    // The position and size will never go out of range of the file length.
    // It may be possible for PDFium to call this function multiple times for
    // the same position.
    // Return value: should be non-zero if successful, zero for error.
    int (*m_GetBlock)(void* param,
                      unsigned long position,
                      unsigned char* pBuf,
                      unsigned long size);

    // A custom pointer for all implementation specific data.  This pointer will
    // be used as the first parameter to the m_GetBlock callback.
    void* m_Param;
} FPDF_FILEACCESS;

// Structure for file reading or writing (I/O).
//
// Note: This is a handler and should be implemented by callers,
// and is only used from XFA.
typedef struct FPDF_FILEHANDLER_ {
    // User-defined data.
    // Note: Callers can use this field to track controls.
    void* clientData;

    // Callback function to release the current file stream object.
    //
    // Parameters:
    //       clientData   -  Pointer to user-defined data.
    // Returns:
    //       None.
    void (*Release)(void* clientData);

    // Callback function to retrieve the current file stream size.
    //
    // Parameters:
    //       clientData   -  Pointer to user-defined data.
    // Returns:
    //       Size of file stream.
    FPDF_DWORD (*GetSize)(void* clientData);

    // Callback function to read data from the current file stream.
    //
    // Parameters:
    //       clientData   -  Pointer to user-defined data.
    //       offset       -  Offset position starts from the beginning of file
    //                       stream. This parameter indicates reading position.
    //       buffer       -  Memory buffer to store data which are read from
    //                       file stream. This parameter should not be NULL.
    //       size         -  Size of data which should be read from file stream,
    //                       in bytes. The buffer indicated by |buffer| must be
    //                       large enough to store specified data.
    // Returns:
    //       0 for success, other value for failure.
    FPDF_RESULT (*ReadBlock)(void* clientData,
     FPDF_DWORD offset,
     void* buffer,
     FPDF_DWORD size);

    // Callback function to write data into the current file stream.
    //
    // Parameters:
    //       clientData   -  Pointer to user-defined data.
    //       offset       -  Offset position starts from the beginning of file
    //                       stream. This parameter indicates writing position.
    //       buffer       -  Memory buffer contains data which is written into
    //                       file stream. This parameter should not be NULL.
    //       size         -  Size of data which should be written into file
    //                       stream, in bytes.
    // Returns:
    //       0 for success, other value for failure.
    FPDF_RESULT (*WriteBlock)(void* clientData,
     FPDF_DWORD offset,
     const void* buffer,
     FPDF_DWORD size);
    // Callback function to flush all internal accessing buffers.
    //
    // Parameters:
    //       clientData   -  Pointer to user-defined data.
    // Returns:
    //       0 for success, other value for failure.
    FPDF_RESULT (*Flush)(void* clientData);

    // Callback function to change file size.
    //
    // Description:
    //       This function is called under writing mode usually. Implementer
    //       can determine whether to realize it based on application requests.
    // Parameters:
    //       clientData   -  Pointer to user-defined data.
    //       size         -  New size of file stream, in bytes.
    // Returns:
    //       0 for success, other value for failure.
    FPDF_RESULT (*Truncate)(void* clientData, FPDF_DWORD size);
} FPDF_FILEHANDLER;

#define FPDF_ERR_SUCCESS 0    // No error.
#define FPDF_ERR_UNKNOWN 1    // Unknown error.
#define FPDF_ERR_FILE 2       // File not found or could not be opened.
#define FPDF_ERR_FORMAT 3     // File not in PDF format or corrupted.
#define FPDF_ERR_PASSWORD 4   // Password required or incorrect password.
#define FPDF_ERR_SECURITY 5   // Unsupported security scheme.
#define FPDF_ERR_PAGE 6       // Page not found or content error.
#ifdef PDF_ENABLE_XFA
#define FPDF_ERR_XFALOAD 7    // Load XFA error.
#define FPDF_ERR_XFALAYOUT 8  // Layout XFA error.
#endif  // PDF_ENABLE_XFA

// Page rendering flags. They can be combined with bit-wise OR.
//
// Set if annotations are to be rendered.
#define FPDF_ANNOT 0x01
// Set if using text rendering optimized for LCD display. This flag will only
// take effect if anti-aliasing is enabled for text.
#define FPDF_LCD_TEXT 0x02
// Don't use the native text output available on some platforms
#define FPDF_NO_NATIVETEXT 0x04
// Grayscale output.
#define FPDF_GRAYSCALE 0x08
// Obsolete, has no effect, retained for compatibility.
#define FPDF_DEBUG_INFO 0x80
// Obsolete, has no effect, retained for compatibility.
#define FPDF_NO_CATCH 0x100
// Limit image cache size.
#define FPDF_RENDER_LIMITEDIMAGECACHE 0x200
// Always use halftone for image stretching.
#define FPDF_RENDER_FORCEHALFTONE 0x400
// Render for printing.
#define FPDF_PRINTING 0x800
// Set to disable anti-aliasing on text. This flag will also disable LCD
// optimization for text rendering.
#define FPDF_RENDER_NO_SMOOTHTEXT 0x1000
// Set to disable anti-aliasing on images.
#define FPDF_RENDER_NO_SMOOTHIMAGE 0x2000
// Set to disable anti-aliasing on paths.
#define FPDF_RENDER_NO_SMOOTHPATH 0x4000
// Set whether to render in a reverse Byte order, this flag is only used when
// rendering to a bitmap.
#define FPDF_REVERSE_BYTE_ORDER 0x10
// Set whether fill paths need to be stroked. This flag is only used when
// FPDF_COLORSCHEME is passed in, since with a single fill color for paths the
// boundaries of adjacent fill paths are less visible.
#define FPDF_CONVERT_FILL_TO_STROKE 0x20

// Struct for color scheme.
// Each should be a 32-bit value specifying the color, in 8888 ARGB format.
typedef struct FPDF_COLORSCHEME_ {
    FPDF_DWORD path_fill_color;
    FPDF_DWORD path_stroke_color;
    FPDF_DWORD text_fill_color;
    FPDF_DWORD text_stroke_color;
} FPDF_COLORSCHEME;

// More DIB formats
// Unknown or unsupported format.
#define FPDFBitmap_Unknown 0
// Gray scale bitmap, one byte per pixel.
#define FPDFBitmap_Gray 1
// 3 bytes per pixel, byte order: blue, green, red.
#define FPDFBitmap_BGR 2
// 4 bytes per pixel, byte order: blue, green, red, unused.
#define FPDFBitmap_BGRx 3
// 4 bytes per pixel, byte order: blue, green, red, alpha.
// Pixel components are independent of alpha.
#define FPDFBitmap_BGRA 4
// 4 bytes per pixel, byte order: blue, green, red, alpha.
// Pixel components are premultiplied by alpha.
// Note that this is experimental and only supported when rendering with
// |FPDF_RENDERER_TYPE| is set to |FPDF_RENDERERTYPE_SKIA|.
#define FPDFBitmap_BGRA_Premul 5

/* cc_file_pdf_pdfium_cfg */
typedef struct
{
    cc_uint8 id;
}cc_file_pdf_pdfium_cfg_struct;

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/****************************************************************************************************
* Function
****************************************************************************************************/

cc_result cc_file_pdf_pdfium_cfg_init(cc_void);
cc_result cc_file_pdf_pdfium_cfg_mainfunction(cc_void);

#endif /* _FILE_PDF_PDFIUM_CFG_H */
/****************************************************************************************************
* File file_pdf_pdfium_cfg.h End!
****************************************************************************************************/

