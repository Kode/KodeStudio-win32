#ifndef HX_STRING_H
#define HX_STRING_H

#ifndef HXCPP_H
#error "Please include hxcpp.h, not hx/Object.h"
#endif

#ifdef __OBJC__
#import <Foundation/Foundation.h>
#endif

// --- String --------------------------------------------------------
//
// Basic String type for hxcpp.
// It's based on garbage collection of the wchar_t (or char ) *ptr.
// Note: this does not inherit from "hx::Object", so in some ways it acts more
// like a standard "int" type than a mode generic class.

#if __cplusplus < 201103L && !defined(_MSC_VER)
typedef unsigned short char16_t;
#endif

class HXCPP_EXTERN_CLASS_ATTRIBUTES String
{
public:
  // These allocate the function using the garbage-colleced malloc
   void *operator new( size_t inSize );
   inline void* operator new( size_t, void* ptr ) { return ptr; }
   void operator delete( void * ) { }

   inline String() : length(0), __s(0) { }
   explicit String(const char *inPtr);
   inline String(const char *inPtr,int inLen) : __s(inPtr), length(inLen) { }

   inline String(const char16_t *inPtr,int inLen,bool) : __w(inPtr), length(inLen) { }

   // Makes copy if required
   String(const wchar_t *inPtr,int inLen);

   explicit String(const wchar_t *inPtr);
   #ifdef __OBJC__
   inline String(NSString *inString)
   {
      *this = String([inString UTF8String]);
   }
   inline operator NSString * () const
   {
      return [[NSString alloc] initWithUTF8String:__s];
   }
   #endif
   #if defined(HX_WINRT) && defined(__cplusplus_winrt)
   inline String(Platform::String^ inString)
   {
      *this = String(inString->Data());
   }
   inline String(Platform::StringReference inString)
   {
      *this = String(inString.Data());
   }
   #endif

   inline String(const ::String &inRHS) : __s(inRHS.__s), length(inRHS.length) { }
   String(const int &inRHS);
   String(const unsigned int &inRHS);
   String(const short &inRHS) { fromInt(inRHS); }
   String(const unsigned short &inRHS) { fromInt(inRHS); }
   String(const signed char &inRHS) { fromInt(inRHS); }
   String(const unsigned char &inRHS) { fromInt(inRHS); }
   String(const cpp::CppInt32__ &inRHS);
   String(const double &inRHS);
   String(const float &inRHS);
   String(const cpp::Int64 &inRHS);
   String(const cpp::UInt64 &inRHS);
   explicit String(const bool &inRHS);
   inline String(const null &inRHS) : __s(0), length(0) { }
   String(hx::Null< ::String > inRHS) : __s(inRHS.value.__s), length(inRHS.value.length) { }
   inline String(const ::cpp::Variant &inRHS) { *this = inRHS.asString(); }

   static void __boot();

   hx::Object *__ToObject() const;

   template<typename T,typename S>
   explicit inline String(const cpp::Struct<T,S> &inRHS);
   template<typename OBJ>
   explicit inline String(const hx::ObjectPtr<OBJ> &inRHS);
   void fromInt(int inI);



   /*
    This causes ambiguous problem with Object==Dynamic (String==Dynamic vs Object==Object)
     and syntactically, String(Dynamic) should be enough I think.
    Could perhaps make it explicit

   template<typename T>
   inline String(const hx::ObjectPtr<T> &inRHS)
   {
      if (inRHS.mPtr)
      {
         ::String s = static_cast<hx::Object *>(inRHS.mPtr)->toString();
         __s = s.__s;
         length = s.length;
      }
      else { __s = 0; length = 0; }
   }
   */
    String(const Dynamic &inRHS);

    inline ::String &operator=(const ::String &inRHS)
           { length = inRHS.length; __s = inRHS.__s; return *this; }

   ::String Default(const ::String &inDef) { return __s ? *this : inDef; }


   ::String toString() { return *this; }

    ::String __URLEncode() const;
    ::String __URLDecode() const;

    ::String &dup();
    ::String &dupConst();
    static ::String makeConstString(const char *);
    static ::String makeConstChar16String(const char *inUtf8, int inLen);

    ::String toUpperCase() const;
    ::String toLowerCase() const;
    ::String charAt(int inPos) const;
    Dynamic charCodeAt(int inPos) const;
    int indexOf(const ::String &inValue, Dynamic inStart) const;
    int lastIndexOf(const ::String &inValue, Dynamic inStart) const;
    Array<String> split(const ::String &inDelimiter) const;
    ::String substr(int inPos,Dynamic inLen) const;
    ::String substring(int inStartIndex, Dynamic inEndIndex) const;

   inline const char *c_str() const { return __CStr(); }
   const char16_t *wc_str() const;
   const char *__CStr() const;
   const wchar_t *__WCStr() const;
   inline operator const char *() { return __CStr(); }

   inline bool isUTF16Encoded() const {
      #ifdef HX_SMART_STRINGS
      return __w && ((unsigned int *)__w)[-1] & HX_GC_STRING_CHAR16_T;
      #else
      return false;
      #endif
   }

   static  ::String fromCharCode(int inCode);

   inline bool operator==(const null &inRHS) const { return __s==0; }
   inline bool operator!=(const null &inRHS) const { return __s!=0; }

   inline int getChar( int index ) {
      if (isUTF16Encoded())
         return __w[index];
      return __s[index];
   }
   inline unsigned int hash( ) const
   {
      if (!__s) return 0;
      if ( __s[HX_GC_STRING_HASH_OFFSET] & HX_GC_STRING_HASH_BIT)
      {
         #ifdef HXCPP_PARANOID
         unsigned int result = calcHash();

         unsigned int have = (((unsigned int *)__s)[-1] & HX_GC_CONST_ALLOC_BIT) ?
                ((unsigned int *)__s)[-2] :  *((unsigned int *)(__s+length+1) );

         if ( have != result )
         {
             printf("Bad string hash for %s\n", __s );
             printf(" Is %08x\n", result );
             printf(" Baked %08x\n", have );
             printf(" Mark %08x\n",   ((unsigned int *)__s)[-1]  );
         }
         #endif
         if (__s[HX_GC_CONST_ALLOC_MARK_OFFSET] & HX_GC_CONST_ALLOC_MARK_BIT)
         {
            #ifdef EMSCRIPTEN
            return  ((emscripten_align1_int*)__s)[-2];
            #else
            return  ((unsigned int *)__s)[-2];
            #endif
         }
        #ifdef EMSCRIPTEN
           return *((emscripten_align1_int *)(__s+length+1) );
        #else
           return *((unsigned int *)(__s+length+1) );
        #endif
      }

      // Slow path..
      return calcHash();
   }

   unsigned int calcHash() const;

   #ifdef HX_SMART_STRINGS
   int compare(const ::String &inRHS) const;
   #else
   inline int compare(const ::String &inRHS) const
   {
      const char *r = inRHS.__s;
      if (__s == r) return inRHS.length-length;
      if (__s==0) return -1;
      if (r==0) return 1;

      return strcmp(__s,r);
      //return memcmp(__s,r,length);
   }
   #endif


   ::String &operator+=(const ::String &inRHS);
   ::String operator+(const ::String &inRHS) const;
   ::String operator+(const int &inRHS) const { return *this + ::String(inRHS); }
   ::String operator+(const bool &inRHS) const { return *this + ::String(inRHS); }
   ::String operator+(const double &inRHS) const { return *this + ::String(inRHS); }
   ::String operator+(const float &inRHS) const { return *this + ::String(inRHS); }
   ::String operator+(const null &inRHS) const{ return *this + HX_CSTRING("null"); } 
   //::String operator+(const char *inRHS) const{ return *this + ::String(inRHS); } 
   ::String operator+(const cpp::CppInt32__ &inRHS) const{ return *this + ::String(inRHS); } 
   template<typename T>
   inline ::String operator+(const hx::ObjectPtr<T> &inRHS) const
      { return *this + (inRHS.mPtr ? const_cast<hx::ObjectPtr<T>&>(inRHS)->toString() : HX_CSTRING("null") ); }
   ::String operator+(const cpp::Variant &inRHS) const{ return *this + inRHS.asString(); } 



   inline bool eq(const ::String &inRHS) const
   {
      #ifdef HX_SMART_STRINGS
      return compare(inRHS)==0;
      #else
      // Strings are known not to be null...
      return length==inRHS.length && !memcmp(__s,inRHS.__s,length);
      #endif
   }

   inline bool operator==(const ::String &inRHS) const { return compare(inRHS)==0; }
   inline bool operator!=(const ::String &inRHS) const { return compare(inRHS)!=0; }

   inline bool operator<(const ::String &inRHS) const { return compare(inRHS)<0; }
   inline bool operator<=(const ::String &inRHS) const { return compare(inRHS)<=0; }
   inline bool operator>(const ::String &inRHS) const { return compare(inRHS)>0; }
   inline bool operator>=(const ::String &inRHS) const { return compare(inRHS)>=0; }

   inline bool operator<(const Dynamic &inRHS) const { return compare(inRHS)<0; }
   inline bool operator<=(const Dynamic &inRHS) const { return compare(inRHS)<=0; }
   inline bool operator>(const Dynamic &inRHS) const { return compare(inRHS)>0; }
   inline bool operator>=(const Dynamic &inRHS) const { return compare(inRHS)>=0; }

   inline int cca(int inPos) const
   {
      if ((unsigned)inPos>=length) return 0;
      #ifdef HX_SMART_STRINGS
      if (isUTF16Encoded())
         return __w[inPos];
      #endif
      return ((unsigned char *)__s)[inPos];
   }

   static char16_t *allocChar16Ptr(int len);


   static  Dynamic fromCharCode_dyn();

   Dynamic charAt_dyn();
   Dynamic charCodeAt_dyn();
   Dynamic indexOf_dyn();
   Dynamic lastIndexOf_dyn();
   Dynamic split_dyn();
   Dynamic substr_dyn();
   Dynamic substring_dyn();
   Dynamic toLowerCase_dyn();
   Dynamic toString_dyn();
   Dynamic toUpperCase_dyn();

   // This is used by the string-wrapped-as-dynamic class
   hx::Val __Field(const ::String &inString, hx::PropertyAccess inCallProp);

   // The actual implementation.
   // Note that "__s" is const - if you want to change it, you should create a new string.
   //  this allows for multiple strings to point to the same data.
   int length;
   union {
      const char *__s;
      const char16_t *__w;
   };
};


inline HXCPP_EXTERN_CLASS_ATTRIBUTES String _hx_string_create(const char *str, int len)
{
   return String(str,len).dup();
}

inline int HXCPP_EXTERN_CLASS_ATTRIBUTES _hx_string_compare(String inString0, String inString1)
{
   return inString0.compare(inString1);
}

String HXCPP_EXTERN_CLASS_ATTRIBUTES _hx_utf8_to_utf16(const unsigned char *ptr, int inUtf8Len, bool addHash);

int HXCPP_EXTERN_CLASS_ATTRIBUTES _hx_utf8_char_code_at(String inString, int inIndex);
int HXCPP_EXTERN_CLASS_ATTRIBUTES _hx_utf8_length(String inString);
bool HXCPP_EXTERN_CLASS_ATTRIBUTES _hx_utf8_is_valid(String inString);
String HXCPP_EXTERN_CLASS_ATTRIBUTES _hx_utf8_sub(String inString0, int inStart, int inLen);
int HXCPP_EXTERN_CLASS_ATTRIBUTES _hx_utf8_decode_advance(char *&ioPtr);


#endif
