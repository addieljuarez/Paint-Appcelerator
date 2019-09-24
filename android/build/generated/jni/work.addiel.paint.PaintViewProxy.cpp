/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2011-2018 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

/** This code is generated, do not edit by hand. **/

#include "work.addiel.paint.PaintViewProxy.h"

#include "AndroidUtil.h"
#include "JNIUtil.h"
#include "JSException.h"
#include "TypeConverter.h"
#include "V8Util.h"


#include "org.appcelerator.titanium.proxy.TiViewProxy.h"

#define TAG "PaintViewProxy"

using namespace v8;

namespace work {
namespace addiel {
namespace paint {
	namespace paint {


Persistent<FunctionTemplate> PaintViewProxy::proxyTemplate;
jclass PaintViewProxy::javaClass = NULL;

PaintViewProxy::PaintViewProxy() : titanium::Proxy()
{
}

void PaintViewProxy::bindProxy(Local<Object> exports, Local<Context> context)
{
	Isolate* isolate = context->GetIsolate();

	Local<FunctionTemplate> pt = getProxyTemplate(isolate);

	v8::TryCatch tryCatch(isolate);
	Local<Function> constructor;
	MaybeLocal<Function> maybeConstructor = pt->GetFunction(context);
	if (!maybeConstructor.ToLocal(&constructor)) {
		titanium::V8Util::fatalException(isolate, tryCatch);
		return;
	}

	Local<String> nameSymbol = NEW_SYMBOL(isolate, "PaintView"); // use symbol over string for efficiency
	exports->Set(context, nameSymbol, constructor);
}

void PaintViewProxy::dispose(Isolate* isolate)
{
	LOGD(TAG, "dispose()");
	if (!proxyTemplate.IsEmpty()) {
		proxyTemplate.Reset();
	}

	titanium::TiViewProxy::dispose(isolate);
}

Local<FunctionTemplate> PaintViewProxy::getProxyTemplate(v8::Isolate* isolate)
{
	Local<Context> context = isolate->GetCurrentContext();
	if (!proxyTemplate.IsEmpty()) {
		return proxyTemplate.Get(isolate);
	}

	LOGD(TAG, "PaintViewProxy::getProxyTemplate()");

	javaClass = titanium::JNIUtil::findClass("work/addiel/paint/PaintViewProxy");
	EscapableHandleScope scope(isolate);

	// use symbol over string for efficiency
	Local<String> nameSymbol = NEW_SYMBOL(isolate, "PaintView");

	Local<FunctionTemplate> t = titanium::Proxy::inheritProxyTemplate(
		isolate,
		titanium::TiViewProxy::getProxyTemplate(isolate),
		javaClass,
		nameSymbol);

	proxyTemplate.Reset(isolate, t);
	t->Set(titanium::Proxy::inheritSymbol.Get(isolate), FunctionTemplate::New(isolate, titanium::Proxy::inherit<PaintViewProxy>));

	// Method bindings --------------------------------------------------------
	titanium::SetProtoMethod(isolate, t, "setStrokeAlpha", PaintViewProxy::setStrokeAlpha);
	titanium::SetProtoMethod(isolate, t, "setEraseMode", PaintViewProxy::setEraseMode);
	titanium::SetProtoMethod(isolate, t, "setStrokeWidth", PaintViewProxy::setStrokeWidth);
	titanium::SetProtoMethod(isolate, t, "clear", PaintViewProxy::clear);
	titanium::SetProtoMethod(isolate, t, "setStrokeColor", PaintViewProxy::setStrokeColor);
	titanium::SetProtoMethod(isolate, t, "setImage", PaintViewProxy::setImage);

	Local<ObjectTemplate> prototypeTemplate = t->PrototypeTemplate();
	Local<ObjectTemplate> instanceTemplate = t->InstanceTemplate();

	// Delegate indexed property get and set to the Java proxy.
	instanceTemplate->SetIndexedPropertyHandler(titanium::Proxy::getIndexedProperty,
		titanium::Proxy::setIndexedProperty);

	// Constants --------------------------------------------------------------

	// Dynamic properties -----------------------------------------------------
	instanceTemplate->SetAccessor(
		NEW_SYMBOL(isolate, "strokeWidth"),
		titanium::Proxy::getProperty,
		PaintViewProxy::setter_strokeWidth,
		Local<Value>(),
		DEFAULT,
		static_cast<v8::PropertyAttribute>(v8::DontDelete)
	);
	instanceTemplate->SetAccessor(
		NEW_SYMBOL(isolate, "image"),
		titanium::Proxy::getProperty,
		PaintViewProxy::setter_image,
		Local<Value>(),
		DEFAULT,
		static_cast<v8::PropertyAttribute>(v8::DontDelete)
	);
	instanceTemplate->SetAccessor(
		NEW_SYMBOL(isolate, "eraseMode"),
		titanium::Proxy::getProperty,
		PaintViewProxy::setter_eraseMode,
		Local<Value>(),
		DEFAULT,
		static_cast<v8::PropertyAttribute>(v8::DontDelete)
	);
	instanceTemplate->SetAccessor(
		NEW_SYMBOL(isolate, "strokeColor"),
		titanium::Proxy::getProperty,
		PaintViewProxy::setter_strokeColor,
		Local<Value>(),
		DEFAULT,
		static_cast<v8::PropertyAttribute>(v8::DontDelete)
	);
	instanceTemplate->SetAccessor(
		NEW_SYMBOL(isolate, "strokeAlpha"),
		titanium::Proxy::getProperty,
		PaintViewProxy::setter_strokeAlpha,
		Local<Value>(),
		DEFAULT,
		static_cast<v8::PropertyAttribute>(v8::DontDelete)
	);

	// Accessors --------------------------------------------------------------

	return scope.Escape(t);
}

Local<FunctionTemplate> PaintViewProxy::getProxyTemplate(v8::Local<v8::Context> context)
{
	return getProxyTemplate(context->GetIsolate());
}

// Methods --------------------------------------------------------------------
void PaintViewProxy::setStrokeAlpha(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "setStrokeAlpha()");
	Isolate* isolate = args.GetIsolate();
	Local<Context> context = isolate->GetCurrentContext();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(PaintViewProxy::javaClass, "setStrokeAlpha", "(I)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setStrokeAlpha' with signature '(I)V'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		LOGE(TAG, "Couldn't obtain argument holder");
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	if (args.Length() < 1) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "setStrokeAlpha: Invalid number of arguments. Expected 1 but got %d", args.Length());
		titanium::JSException::Error(isolate, errorStringBuffer);
		return;
	}

	jvalue jArguments[1];




	
		if ((titanium::V8Util::isNaN(isolate, args[0]) && !args[0]->IsUndefined()) || args[0]->ToString(context).FromMaybe(String::Empty(isolate))->Length() == 0) {
			const char *error = "Invalid value, expected type Number.";
			LOGE(TAG, error);
			titanium::JSException::Error(isolate, error);
			return;
		}
		if (!args[0]->IsNull()) {
		MaybeLocal<Number> arg_0 = args[0]->ToNumber(context);
		if (arg_0.IsEmpty()) {
			const char *error = "Invalid argument at index 0, expected type Number and failed to coerce.";
			LOGE(TAG, error);
			titanium::JSException::Error(isolate, error);
			return;
		} else {
			jArguments[0].i =
				titanium::TypeConverter::jsNumberToJavaInt(
					env, arg_0.ToLocalChecked());
		}
	} else {
		jArguments[0].i = NULL;
	}

	LOGW(TAG, "Automatic setter methods for properties are deprecated in SDK 8.0.0 and will be removed in SDK 9.0.0. Please modify the property in standard JS style: obj.strokeAlpha = value; or obj['strokeAlpha'] = value;");

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	args.GetReturnValue().Set(v8::Undefined(isolate));

}
void PaintViewProxy::setEraseMode(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "setEraseMode()");
	Isolate* isolate = args.GetIsolate();
	Local<Context> context = isolate->GetCurrentContext();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(PaintViewProxy::javaClass, "setEraseMode", "(Ljava/lang/Boolean;)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setEraseMode' with signature '(Ljava/lang/Boolean;)V'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		LOGE(TAG, "Couldn't obtain argument holder");
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	if (args.Length() < 1) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "setEraseMode: Invalid number of arguments. Expected 1 but got %d", args.Length());
		titanium::JSException::Error(isolate, errorStringBuffer);
		return;
	}

	jvalue jArguments[1];




	bool isNew_0;
	if (!args[0]->IsNull()) {
		Local<Value> arg_0 = args[0];
		jArguments[0].l =
			titanium::TypeConverter::jsValueToJavaObject(
				isolate,
				env, arg_0, &isNew_0);
	} else {
		jArguments[0].l = NULL;
	}

	LOGW(TAG, "Automatic setter methods for properties are deprecated in SDK 8.0.0 and will be removed in SDK 9.0.0. Please modify the property in standard JS style: obj.eraseMode = value; or obj['eraseMode'] = value;");

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



			if (isNew_0) {
				env->DeleteLocalRef(jArguments[0].l);
			}


	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	args.GetReturnValue().Set(v8::Undefined(isolate));

}
void PaintViewProxy::setStrokeWidth(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "setStrokeWidth()");
	Isolate* isolate = args.GetIsolate();
	Local<Context> context = isolate->GetCurrentContext();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(PaintViewProxy::javaClass, "setStrokeWidth", "(I)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setStrokeWidth' with signature '(I)V'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		LOGE(TAG, "Couldn't obtain argument holder");
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	if (args.Length() < 1) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "setStrokeWidth: Invalid number of arguments. Expected 1 but got %d", args.Length());
		titanium::JSException::Error(isolate, errorStringBuffer);
		return;
	}

	jvalue jArguments[1];




	
		if ((titanium::V8Util::isNaN(isolate, args[0]) && !args[0]->IsUndefined()) || args[0]->ToString(context).FromMaybe(String::Empty(isolate))->Length() == 0) {
			const char *error = "Invalid value, expected type Number.";
			LOGE(TAG, error);
			titanium::JSException::Error(isolate, error);
			return;
		}
		if (!args[0]->IsNull()) {
		MaybeLocal<Number> arg_0 = args[0]->ToNumber(context);
		if (arg_0.IsEmpty()) {
			const char *error = "Invalid argument at index 0, expected type Number and failed to coerce.";
			LOGE(TAG, error);
			titanium::JSException::Error(isolate, error);
			return;
		} else {
			jArguments[0].i =
				titanium::TypeConverter::jsNumberToJavaInt(
					env, arg_0.ToLocalChecked());
		}
	} else {
		jArguments[0].i = NULL;
	}

	LOGW(TAG, "Automatic setter methods for properties are deprecated in SDK 8.0.0 and will be removed in SDK 9.0.0. Please modify the property in standard JS style: obj.strokeWidth = value; or obj['strokeWidth'] = value;");

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	args.GetReturnValue().Set(v8::Undefined(isolate));

}
void PaintViewProxy::clear(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "clear()");
	Isolate* isolate = args.GetIsolate();
	Local<Context> context = isolate->GetCurrentContext();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(PaintViewProxy::javaClass, "clear", "()V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'clear' with signature '()V'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		LOGE(TAG, "Couldn't obtain argument holder");
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	jvalue* jArguments = 0;


	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	args.GetReturnValue().Set(v8::Undefined(isolate));

}
void PaintViewProxy::setStrokeColor(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "setStrokeColor()");
	Isolate* isolate = args.GetIsolate();
	Local<Context> context = isolate->GetCurrentContext();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(PaintViewProxy::javaClass, "setStrokeColor", "(Ljava/lang/String;)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setStrokeColor' with signature '(Ljava/lang/String;)V'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		LOGE(TAG, "Couldn't obtain argument holder");
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	if (args.Length() < 1) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "setStrokeColor: Invalid number of arguments. Expected 1 but got %d", args.Length());
		titanium::JSException::Error(isolate, errorStringBuffer);
		return;
	}

	jvalue jArguments[1];




	
	if (!args[0]->IsNull()) {
		Local<Value> arg_0 = args[0];
		jArguments[0].l =
			titanium::TypeConverter::jsValueToJavaString(
				isolate,
				env, arg_0);
	} else {
		jArguments[0].l = NULL;
	}

	LOGW(TAG, "Automatic setter methods for properties are deprecated in SDK 8.0.0 and will be removed in SDK 9.0.0. Please modify the property in standard JS style: obj.strokeColor = value; or obj['strokeColor'] = value;");

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



				env->DeleteLocalRef(jArguments[0].l);


	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	args.GetReturnValue().Set(v8::Undefined(isolate));

}
void PaintViewProxy::setImage(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "setImage()");
	Isolate* isolate = args.GetIsolate();
	Local<Context> context = isolate->GetCurrentContext();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(PaintViewProxy::javaClass, "setImage", "(Ljava/lang/String;)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setImage' with signature '(Ljava/lang/String;)V'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		LOGE(TAG, "Couldn't obtain argument holder");
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	if (args.Length() < 1) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "setImage: Invalid number of arguments. Expected 1 but got %d", args.Length());
		titanium::JSException::Error(isolate, errorStringBuffer);
		return;
	}

	jvalue jArguments[1];




	
	if (!args[0]->IsNull()) {
		Local<Value> arg_0 = args[0];
		jArguments[0].l =
			titanium::TypeConverter::jsValueToJavaString(
				isolate,
				env, arg_0);
	} else {
		jArguments[0].l = NULL;
	}

	LOGW(TAG, "Automatic setter methods for properties are deprecated in SDK 8.0.0 and will be removed in SDK 9.0.0. Please modify the property in standard JS style: obj.image = value; or obj['image'] = value;");

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



				env->DeleteLocalRef(jArguments[0].l);


	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	args.GetReturnValue().Set(v8::Undefined(isolate));

}

// Dynamic property accessors -------------------------------------------------


void PaintViewProxy::setter_strokeWidth(Local<Name> property, Local<Value> value, const PropertyCallbackInfo<void>& args)
{
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		LOGE(TAG, "Failed to get environment, strokeWidth wasn't set");
		return;
	}

	Local<Context> context = isolate->GetCurrentContext();

	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(PaintViewProxy::javaClass, "setStrokeWidth", "(I)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setStrokeWidth' with signature '(I)V'";
			LOGE(TAG, error);
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		LOGE(TAG, "Couldn't obtain argument holder");
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		return;
	}

	jvalue jArguments[1];

	
		if ((titanium::V8Util::isNaN(isolate, value) && !value->IsUndefined()) || value->ToString(context).FromMaybe(String::Empty(isolate))->Length() == 0) {
			const char *error = "Invalid value, expected type Number.";
			LOGE(TAG, error);
		}
		if (!value->IsNull()) {
		MaybeLocal<Number> arg_0 = value->ToNumber(context);
		if (arg_0.IsEmpty()) {
			const char *error = "Invalid argument at index 0, expected type Number and failed to coerce.";
			LOGE(TAG, error);
			jArguments[0].i = NULL;
		} else {
			jArguments[0].i =
				titanium::TypeConverter::jsNumberToJavaInt(
					env, arg_0.ToLocalChecked());
		}
	} else {
		jArguments[0].i = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	Proxy::setProperty(property, value, args);
}



void PaintViewProxy::setter_image(Local<Name> property, Local<Value> value, const PropertyCallbackInfo<void>& args)
{
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		LOGE(TAG, "Failed to get environment, image wasn't set");
		return;
	}

	Local<Context> context = isolate->GetCurrentContext();

	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(PaintViewProxy::javaClass, "setImage", "(Ljava/lang/String;)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setImage' with signature '(Ljava/lang/String;)V'";
			LOGE(TAG, error);
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		LOGE(TAG, "Couldn't obtain argument holder");
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		return;
	}

	jvalue jArguments[1];

	
	if (!value->IsNull()) {
		Local<Value> arg_0 = value;
		jArguments[0].l =
			titanium::TypeConverter::jsValueToJavaString(
				isolate,
				env, arg_0);
	} else {
		jArguments[0].l = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



				env->DeleteLocalRef(jArguments[0].l);


	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	Proxy::setProperty(property, value, args);
}



void PaintViewProxy::setter_eraseMode(Local<Name> property, Local<Value> value, const PropertyCallbackInfo<void>& args)
{
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		LOGE(TAG, "Failed to get environment, eraseMode wasn't set");
		return;
	}

	Local<Context> context = isolate->GetCurrentContext();

	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(PaintViewProxy::javaClass, "setEraseMode", "(Ljava/lang/Boolean;)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setEraseMode' with signature '(Ljava/lang/Boolean;)V'";
			LOGE(TAG, error);
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		LOGE(TAG, "Couldn't obtain argument holder");
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		return;
	}

	jvalue jArguments[1];

	bool isNew_0;
	if (!value->IsNull()) {
		Local<Value> arg_0 = value;
		jArguments[0].l =
			titanium::TypeConverter::jsValueToJavaObject(
				isolate,
				env, arg_0, &isNew_0);
	} else {
		jArguments[0].l = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



			if (isNew_0) {
				env->DeleteLocalRef(jArguments[0].l);
			}


	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	Proxy::setProperty(property, value, args);
}



void PaintViewProxy::setter_strokeColor(Local<Name> property, Local<Value> value, const PropertyCallbackInfo<void>& args)
{
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		LOGE(TAG, "Failed to get environment, strokeColor wasn't set");
		return;
	}

	Local<Context> context = isolate->GetCurrentContext();

	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(PaintViewProxy::javaClass, "setStrokeColor", "(Ljava/lang/String;)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setStrokeColor' with signature '(Ljava/lang/String;)V'";
			LOGE(TAG, error);
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		LOGE(TAG, "Couldn't obtain argument holder");
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		return;
	}

	jvalue jArguments[1];

	
	if (!value->IsNull()) {
		Local<Value> arg_0 = value;
		jArguments[0].l =
			titanium::TypeConverter::jsValueToJavaString(
				isolate,
				env, arg_0);
	} else {
		jArguments[0].l = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



				env->DeleteLocalRef(jArguments[0].l);


	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	Proxy::setProperty(property, value, args);
}



void PaintViewProxy::setter_strokeAlpha(Local<Name> property, Local<Value> value, const PropertyCallbackInfo<void>& args)
{
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		LOGE(TAG, "Failed to get environment, strokeAlpha wasn't set");
		return;
	}

	Local<Context> context = isolate->GetCurrentContext();

	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(PaintViewProxy::javaClass, "setStrokeAlpha", "(I)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setStrokeAlpha' with signature '(I)V'";
			LOGE(TAG, error);
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		LOGE(TAG, "Couldn't obtain argument holder");
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		return;
	}

	jvalue jArguments[1];

	
		if ((titanium::V8Util::isNaN(isolate, value) && !value->IsUndefined()) || value->ToString(context).FromMaybe(String::Empty(isolate))->Length() == 0) {
			const char *error = "Invalid value, expected type Number.";
			LOGE(TAG, error);
		}
		if (!value->IsNull()) {
		MaybeLocal<Number> arg_0 = value->ToNumber(context);
		if (arg_0.IsEmpty()) {
			const char *error = "Invalid argument at index 0, expected type Number and failed to coerce.";
			LOGE(TAG, error);
			jArguments[0].i = NULL;
		} else {
			jArguments[0].i =
				titanium::TypeConverter::jsNumberToJavaInt(
					env, arg_0.ToLocalChecked());
		}
	} else {
		jArguments[0].i = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	Proxy::setProperty(property, value, args);
}



	} // namespace paint
} // paint
} // addiel
} // work
