/* ------------------------------------------------------------
author: "Ali"
name: "SpectralFX"
Code generated with Faust 2.94.1 (https://faust.grame.fr)
Compilation options: -a /tmp/tmp.p3JJ0EK44K -lang cpp -fpga-mem-th 4 -ct 1 -cn FaustResonateur -scn FaustBase -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __FaustResonateur_H__
#define  __FaustResonateur_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>
#ifndef FAUST_INT_WRAP
#define FAUST_INT_WRAP
inline int faust_wrap_add(int a, int b) { return int((unsigned int)a + (unsigned int)b); }
inline int faust_wrap_sub(int a, int b) { return int((unsigned int)a - (unsigned int)b); }
inline int faust_wrap_mul(int a, int b) { return int((unsigned int)a * (unsigned int)b); }
#endif


#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustResonateur
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

#if defined(_WIN32)
#define RESTRICT __restrict
#else
#define RESTRICT __restrict__
#endif

static double FaustResonateur_faustpower2_f(double value_f) {
	return value_f * value_f;
}

class FaustResonateur : public FaustBase {
	
 private:
	
	FAUSTFLOAT fHslider0;
	double fVec0[2];
	int fSampleRate;
	double fConst0;
	double fConst1;
	int iVec1[2];
	double fRec0[2];
	double fConst2;
	FAUSTFLOAT fHslider1;
	double fVec2[2];
	double fRec3[2];
	double fConst3;
	FAUSTFLOAT fHslider2;
	double fVec3[2];
	double fRec12[2];
	double fConst4;
	FAUSTFLOAT fCheckbox0;
	FAUSTFLOAT fHslider3;
	double fVec4[2];
	FAUSTFLOAT fEntry0;
	int iVec5[2];
	double fConst5;
	double fRec13[2];
	double fConst6;
	double fRec14[2];
	FAUSTFLOAT fHslider4;
	double fVec6[2];
	double fRec15[2];
	double fConst7;
	double fConst8;
	double fConst9;
	double fConst10;
	double fConst11;
	double fConst12;
	double fConst13;
	double fRec19[2];
	double fRec20[2];
	int iRec21[2];
	double fRec18[2];
	double fRec16[2];
	double fConst14;
	double fRec17[2];
	FAUSTFLOAT fHslider5;
	double fVec7[2];
	double fRec22[2];
	int IOTA0;
	double fVec8[32768];
	double fVec9[2];
	double fRec5[2];
	double fRec6[2];
	double fRec7[2];
	double fRec8[2];
	FAUSTFLOAT fHslider6;
	double fVec10[2];
	double fRec23[2];
	double fConst15;
	double fRec9[2];
	double fRec11[2];
	double fVec11[2];
	double fRec31[2];
	double fConst16;
	double fConst17;
	double fConst18;
	double fConst19;
	double fConst20;
	double fConst21;
	double fConst22;
	double fRec35[2];
	double fRec36[2];
	double fRec34[2];
	double fRec32[2];
	double fConst23;
	double fRec33[2];
	double fVec12[32768];
	double fVec13[2];
	double fRec24[2];
	double fRec25[2];
	double fRec26[2];
	double fRec27[2];
	double fRec28[2];
	double fRec30[2];
	double fVec14[2];
	double fRec44[2];
	double fConst24;
	double fConst25;
	double fConst26;
	double fConst27;
	double fConst28;
	double fConst29;
	double fConst30;
	double fRec48[2];
	double fRec49[2];
	double fRec47[2];
	double fRec45[2];
	double fConst31;
	double fRec46[2];
	double fVec15[32768];
	double fVec16[2];
	double fRec37[2];
	double fRec38[2];
	double fRec39[2];
	double fRec40[2];
	double fRec41[2];
	double fRec43[2];
	double fVec17[2];
	double fRec57[2];
	double fConst32;
	double fConst33;
	double fConst34;
	double fConst35;
	double fConst36;
	double fConst37;
	double fConst38;
	double fRec61[2];
	double fRec62[2];
	double fRec60[2];
	double fRec58[2];
	double fConst39;
	double fRec59[2];
	double fVec18[32768];
	double fVec19[2];
	double fRec50[2];
	double fRec51[2];
	double fRec52[2];
	double fRec53[2];
	double fRec54[2];
	double fRec56[2];
	double fVec20[2];
	double fRec4[2];
	double fRec1[2];
	double fRec2[2];
	double fConst40;
	double fConst41;
	double fConst42;
	double fConst43;
	double fConst44;
	double fConst45;
	double fConst46;
	double fRec76[2];
	double fRec77[2];
	double fRec75[2];
	double fRec73[2];
	double fConst47;
	double fRec74[2];
	double fVec21[32768];
	double fVec22[2];
	double fRec66[2];
	double fRec67[2];
	double fRec68[2];
	double fRec69[2];
	double fRec70[2];
	double fRec72[2];
	double fConst48;
	double fConst49;
	double fConst50;
	double fConst51;
	double fConst52;
	double fConst53;
	double fConst54;
	double fRec88[2];
	double fRec89[2];
	double fRec87[2];
	double fRec85[2];
	double fConst55;
	double fRec86[2];
	double fVec23[32768];
	double fVec24[2];
	double fRec78[2];
	double fRec79[2];
	double fRec80[2];
	double fRec81[2];
	double fRec82[2];
	double fRec84[2];
	double fConst56;
	double fConst57;
	double fConst58;
	double fConst59;
	double fConst60;
	double fConst61;
	double fConst62;
	double fRec100[2];
	double fRec101[2];
	double fRec99[2];
	double fRec97[2];
	double fConst63;
	double fRec98[2];
	double fVec25[32768];
	double fVec26[2];
	double fRec90[2];
	double fRec91[2];
	double fRec92[2];
	double fRec93[2];
	double fRec94[2];
	double fRec96[2];
	double fConst64;
	double fConst65;
	double fConst66;
	double fConst67;
	double fConst68;
	double fConst69;
	double fConst70;
	double fRec112[2];
	double fRec113[2];
	double fRec111[2];
	double fRec109[2];
	double fConst71;
	double fRec110[2];
	double fVec27[32768];
	double fVec28[2];
	double fRec102[2];
	double fRec103[2];
	double fRec104[2];
	double fRec105[2];
	double fRec106[2];
	double fRec108[2];
	double fVec29[2];
	double fRec65[2];
	double fRec63[2];
	double fRec64[2];
	
 public:
	FaustResonateur() {
	}
	
	FaustResonateur(const FaustResonateur&) = default;
	
	virtual ~FaustResonateur() = default;
	
	FaustResonateur& operator=(const FaustResonateur&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "Ali");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/sAndH:author", "Romain Michon");
		m->declare("basics.lib/version", "1.23.9");
		m->declare("compile_options", "-a /tmp/tmp.p3JJ0EK44K -lang cpp -fpga-mem-th 4 -ct 1 -cn FaustResonateur -scn FaustBase -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("delays.lib/fdelay3:author", "Julius O. Smith III");
		m->declare("delays.lib/fdelayltv:author", "Julius O. Smith III");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.3.4");
		m->declare("filename", "resonateur.dsp");
		m->declare("filters.lib/_tanhalf:author", "Julius O. Smith III");
		m->declare("filters.lib/_tanhalf:license", "MIT");
		m->declare("filters.lib/dcblocker:author", "Julius O. Smith III");
		m->declare("filters.lib/dcblocker:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/dcblocker:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass0_highpass1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass0_highpass1:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/nlf2:author", "Julius O. Smith III");
		m->declare("filters.lib/nlf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/nlf2:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/pole:author", "Julius O. Smith III");
		m->declare("filters.lib/pole:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/pole:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/svf:author", "Oleg Nesterov");
		m->declare("filters.lib/svf:copyright", "Copyright (C) 2020 Oleg Nesterov <oleg@redhat.com>");
		m->declare("filters.lib/svf:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/tf1s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1s:license", "LicenseRef-STK-4.3");
		m->declare("filters.lib/version", "1.13.6");
		m->declare("filters.lib/zero:author", "Julius O. Smith III");
		m->declare("filters.lib/zero:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/zero:license", "LicenseRef-STK-4.3");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.5");
		m->declare("name", "SpectralFX");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "1.9.2");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "1.9.6");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.2");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "1.4.1");
		m->declare("signals.lib/name", "Faust Routing Library");
		m->declare("signals.lib/version", "1.8.2");
	}

	virtual int getNumInputs() {
		return 2;
	}
	virtual int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<double>(1.92e+05, std::max<double>(5e+01, static_cast<double>(fSampleRate)));
		fConst1 = 1.0 - 44.1 / fConst0;
		fConst2 = 3.141592653589793 / fConst0;
		fConst3 = std::pow(0.995, 4.41e+04 / fConst0);
		fConst4 = 0.0022727272727272726 * fConst0;
		fConst5 = std::exp(-(25.0 / fConst0));
		fConst6 = std::exp(-(2e+01 / fConst0));
		fConst7 = std::tan(std::max<double>(0.0, std::min<double>(0.5340707511102649 / fConst0, 1.5676547341413067)));
		fConst8 = fConst7 + 1.414213562373095;
		fConst9 = fConst7 * std::min<double>(1.7976931348623157e+308, 1.0 / (fConst7 * fConst8 + 1.0));
		fConst10 = 2.0 * fConst9;
		fConst11 = 1.0681415022205298 / fConst0;
		fConst12 = std::sin(fConst11);
		fConst13 = std::cos(fConst11);
		fConst14 = 2.0 * fConst7;
		fConst15 = 0.45 * fConst0;
		fConst16 = std::tan(std::max<double>(0.0, std::min<double>(0.7225663103256524 / fConst0, 1.5676547341413067)));
		fConst17 = fConst16 + 1.414213562373095;
		fConst18 = fConst16 * std::min<double>(1.7976931348623157e+308, 1.0 / (fConst16 * fConst17 + 1.0));
		fConst19 = 2.0 * fConst18;
		fConst20 = 1.4451326206513049 / fConst0;
		fConst21 = std::sin(fConst20);
		fConst22 = std::cos(fConst20);
		fConst23 = 2.0 * fConst16;
		fConst24 = std::tan(std::max<double>(0.0, std::min<double>(0.91106186954104 / fConst0, 1.5676547341413067)));
		fConst25 = fConst24 + 1.414213562373095;
		fConst26 = fConst24 * std::min<double>(1.7976931348623157e+308, 1.0 / (fConst24 * fConst25 + 1.0));
		fConst27 = 2.0 * fConst26;
		fConst28 = 1.82212373908208 / fConst0;
		fConst29 = std::sin(fConst28);
		fConst30 = std::cos(fConst28);
		fConst31 = 2.0 * fConst24;
		fConst32 = std::tan(std::max<double>(0.0, std::min<double>(1.1623892818282235 / fConst0, 1.5676547341413067)));
		fConst33 = fConst32 + 1.414213562373095;
		fConst34 = fConst32 * std::min<double>(1.7976931348623157e+308, 1.0 / (fConst32 * fConst33 + 1.0));
		fConst35 = 2.0 * fConst34;
		fConst36 = 2.324778563656447 / fConst0;
		fConst37 = std::sin(fConst36);
		fConst38 = std::cos(fConst36);
		fConst39 = 2.0 * fConst32;
		fConst40 = std::tan(std::max<double>(0.0, std::min<double>(0.5969026041820606 / fConst0, 1.5676547341413067)));
		fConst41 = fConst40 + 1.414213562373095;
		fConst42 = fConst40 * std::min<double>(1.7976931348623157e+308, 1.0 / (fConst40 * fConst41 + 1.0));
		fConst43 = 2.0 * fConst42;
		fConst44 = 1.1938052083641213 / fConst0;
		fConst45 = std::sin(fConst44);
		fConst46 = std::cos(fConst44);
		fConst47 = 2.0 * fConst40;
		fConst48 = std::tan(std::max<double>(0.0, std::min<double>(0.9738937226128359 / fConst0, 1.5676547341413067)));
		fConst49 = fConst48 + 1.414213562373095;
		fConst50 = fConst48 * std::min<double>(1.7976931348623157e+308, 1.0 / (fConst48 * fConst49 + 1.0));
		fConst51 = 2.0 * fConst50;
		fConst52 = 1.9477874452256718 / fConst0;
		fConst53 = std::sin(fConst52);
		fConst54 = std::cos(fConst52);
		fConst55 = 2.0 * fConst48;
		fConst56 = std::tan(std::max<double>(0.0, std::min<double>(1.288052987971815 / fConst0, 1.5676547341413067)));
		fConst57 = fConst56 + 1.414213562373095;
		fConst58 = fConst56 * std::min<double>(1.7976931348623157e+308, 1.0 / (fConst56 * fConst57 + 1.0));
		fConst59 = 2.0 * fConst58;
		fConst60 = 2.57610597594363 / fConst0;
		fConst61 = std::sin(fConst60);
		fConst62 = std::cos(fConst60);
		fConst63 = 2.0 * fConst56;
		fConst64 = std::tan(std::max<double>(0.0, std::min<double>(0.4084070449666731 / fConst0, 1.5676547341413067)));
		fConst65 = fConst64 + 1.414213562373095;
		fConst66 = fConst64 * std::min<double>(1.7976931348623157e+308, 1.0 / (fConst64 * fConst65 + 1.0));
		fConst67 = 2.0 * fConst66;
		fConst68 = 0.8168140899333463 / fConst0;
		fConst69 = std::sin(fConst68);
		fConst70 = std::cos(fConst68);
		fConst71 = 2.0 * fConst64;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(0.7);
		fHslider1 = static_cast<FAUSTFLOAT>(0.3);
		fHslider2 = static_cast<FAUSTFLOAT>(0.2);
		fCheckbox0 = static_cast<FAUSTFLOAT>(0.0);
		fHslider3 = static_cast<FAUSTFLOAT>(4e+01);
		fEntry0 = static_cast<FAUSTFLOAT>(2.0);
		fHslider4 = static_cast<FAUSTFLOAT>(0.3);
		fHslider5 = static_cast<FAUSTFLOAT>(3.0);
		fHslider6 = static_cast<FAUSTFLOAT>(0.6);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fVec0[l0] = 0.0;
		}
		for (int l1 = 0; l1 < 2; l1 = faust_wrap_add(l1, 1)) {
			iVec1[l1] = 0;
		}
		for (int l2 = 0; l2 < 2; l2 = faust_wrap_add(l2, 1)) {
			fRec0[l2] = 0.0;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fVec2[l3] = 0.0;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fRec3[l4] = 0.0;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fVec3[l5] = 0.0;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fRec12[l6] = 0.0;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fVec4[l7] = 0.0;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			iVec5[l8] = 0;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fRec13[l9] = 0.0;
		}
		for (int l10 = 0; l10 < 2; l10 = faust_wrap_add(l10, 1)) {
			fRec14[l10] = 0.0;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			fVec6[l11] = 0.0;
		}
		for (int l12 = 0; l12 < 2; l12 = faust_wrap_add(l12, 1)) {
			fRec15[l12] = 0.0;
		}
		for (int l13 = 0; l13 < 2; l13 = faust_wrap_add(l13, 1)) {
			fRec19[l13] = 0.0;
		}
		for (int l14 = 0; l14 < 2; l14 = faust_wrap_add(l14, 1)) {
			fRec20[l14] = 0.0;
		}
		for (int l15 = 0; l15 < 2; l15 = faust_wrap_add(l15, 1)) {
			iRec21[l15] = 0;
		}
		for (int l16 = 0; l16 < 2; l16 = faust_wrap_add(l16, 1)) {
			fRec18[l16] = 0.0;
		}
		for (int l17 = 0; l17 < 2; l17 = faust_wrap_add(l17, 1)) {
			fRec16[l17] = 0.0;
		}
		for (int l18 = 0; l18 < 2; l18 = faust_wrap_add(l18, 1)) {
			fRec17[l18] = 0.0;
		}
		for (int l19 = 0; l19 < 2; l19 = faust_wrap_add(l19, 1)) {
			fVec7[l19] = 0.0;
		}
		for (int l20 = 0; l20 < 2; l20 = faust_wrap_add(l20, 1)) {
			fRec22[l20] = 0.0;
		}
		IOTA0 = 0;
		for (int l21 = 0; l21 < 32768; l21 = faust_wrap_add(l21, 1)) {
			fVec8[l21] = 0.0;
		}
		for (int l22 = 0; l22 < 2; l22 = faust_wrap_add(l22, 1)) {
			fVec9[l22] = 0.0;
		}
		for (int l23 = 0; l23 < 2; l23 = faust_wrap_add(l23, 1)) {
			fRec5[l23] = 0.0;
		}
		for (int l24 = 0; l24 < 2; l24 = faust_wrap_add(l24, 1)) {
			fRec6[l24] = 0.0;
		}
		for (int l25 = 0; l25 < 2; l25 = faust_wrap_add(l25, 1)) {
			fRec7[l25] = 0.0;
		}
		for (int l26 = 0; l26 < 2; l26 = faust_wrap_add(l26, 1)) {
			fRec8[l26] = 0.0;
		}
		for (int l27 = 0; l27 < 2; l27 = faust_wrap_add(l27, 1)) {
			fVec10[l27] = 0.0;
		}
		for (int l28 = 0; l28 < 2; l28 = faust_wrap_add(l28, 1)) {
			fRec23[l28] = 0.0;
		}
		for (int l29 = 0; l29 < 2; l29 = faust_wrap_add(l29, 1)) {
			fRec9[l29] = 0.0;
		}
		for (int l30 = 0; l30 < 2; l30 = faust_wrap_add(l30, 1)) {
			fRec11[l30] = 0.0;
		}
		for (int l31 = 0; l31 < 2; l31 = faust_wrap_add(l31, 1)) {
			fVec11[l31] = 0.0;
		}
		for (int l32 = 0; l32 < 2; l32 = faust_wrap_add(l32, 1)) {
			fRec31[l32] = 0.0;
		}
		for (int l33 = 0; l33 < 2; l33 = faust_wrap_add(l33, 1)) {
			fRec35[l33] = 0.0;
		}
		for (int l34 = 0; l34 < 2; l34 = faust_wrap_add(l34, 1)) {
			fRec36[l34] = 0.0;
		}
		for (int l35 = 0; l35 < 2; l35 = faust_wrap_add(l35, 1)) {
			fRec34[l35] = 0.0;
		}
		for (int l36 = 0; l36 < 2; l36 = faust_wrap_add(l36, 1)) {
			fRec32[l36] = 0.0;
		}
		for (int l37 = 0; l37 < 2; l37 = faust_wrap_add(l37, 1)) {
			fRec33[l37] = 0.0;
		}
		for (int l38 = 0; l38 < 32768; l38 = faust_wrap_add(l38, 1)) {
			fVec12[l38] = 0.0;
		}
		for (int l39 = 0; l39 < 2; l39 = faust_wrap_add(l39, 1)) {
			fVec13[l39] = 0.0;
		}
		for (int l40 = 0; l40 < 2; l40 = faust_wrap_add(l40, 1)) {
			fRec24[l40] = 0.0;
		}
		for (int l41 = 0; l41 < 2; l41 = faust_wrap_add(l41, 1)) {
			fRec25[l41] = 0.0;
		}
		for (int l42 = 0; l42 < 2; l42 = faust_wrap_add(l42, 1)) {
			fRec26[l42] = 0.0;
		}
		for (int l43 = 0; l43 < 2; l43 = faust_wrap_add(l43, 1)) {
			fRec27[l43] = 0.0;
		}
		for (int l44 = 0; l44 < 2; l44 = faust_wrap_add(l44, 1)) {
			fRec28[l44] = 0.0;
		}
		for (int l45 = 0; l45 < 2; l45 = faust_wrap_add(l45, 1)) {
			fRec30[l45] = 0.0;
		}
		for (int l46 = 0; l46 < 2; l46 = faust_wrap_add(l46, 1)) {
			fVec14[l46] = 0.0;
		}
		for (int l47 = 0; l47 < 2; l47 = faust_wrap_add(l47, 1)) {
			fRec44[l47] = 0.0;
		}
		for (int l48 = 0; l48 < 2; l48 = faust_wrap_add(l48, 1)) {
			fRec48[l48] = 0.0;
		}
		for (int l49 = 0; l49 < 2; l49 = faust_wrap_add(l49, 1)) {
			fRec49[l49] = 0.0;
		}
		for (int l50 = 0; l50 < 2; l50 = faust_wrap_add(l50, 1)) {
			fRec47[l50] = 0.0;
		}
		for (int l51 = 0; l51 < 2; l51 = faust_wrap_add(l51, 1)) {
			fRec45[l51] = 0.0;
		}
		for (int l52 = 0; l52 < 2; l52 = faust_wrap_add(l52, 1)) {
			fRec46[l52] = 0.0;
		}
		for (int l53 = 0; l53 < 32768; l53 = faust_wrap_add(l53, 1)) {
			fVec15[l53] = 0.0;
		}
		for (int l54 = 0; l54 < 2; l54 = faust_wrap_add(l54, 1)) {
			fVec16[l54] = 0.0;
		}
		for (int l55 = 0; l55 < 2; l55 = faust_wrap_add(l55, 1)) {
			fRec37[l55] = 0.0;
		}
		for (int l56 = 0; l56 < 2; l56 = faust_wrap_add(l56, 1)) {
			fRec38[l56] = 0.0;
		}
		for (int l57 = 0; l57 < 2; l57 = faust_wrap_add(l57, 1)) {
			fRec39[l57] = 0.0;
		}
		for (int l58 = 0; l58 < 2; l58 = faust_wrap_add(l58, 1)) {
			fRec40[l58] = 0.0;
		}
		for (int l59 = 0; l59 < 2; l59 = faust_wrap_add(l59, 1)) {
			fRec41[l59] = 0.0;
		}
		for (int l60 = 0; l60 < 2; l60 = faust_wrap_add(l60, 1)) {
			fRec43[l60] = 0.0;
		}
		for (int l61 = 0; l61 < 2; l61 = faust_wrap_add(l61, 1)) {
			fVec17[l61] = 0.0;
		}
		for (int l62 = 0; l62 < 2; l62 = faust_wrap_add(l62, 1)) {
			fRec57[l62] = 0.0;
		}
		for (int l63 = 0; l63 < 2; l63 = faust_wrap_add(l63, 1)) {
			fRec61[l63] = 0.0;
		}
		for (int l64 = 0; l64 < 2; l64 = faust_wrap_add(l64, 1)) {
			fRec62[l64] = 0.0;
		}
		for (int l65 = 0; l65 < 2; l65 = faust_wrap_add(l65, 1)) {
			fRec60[l65] = 0.0;
		}
		for (int l66 = 0; l66 < 2; l66 = faust_wrap_add(l66, 1)) {
			fRec58[l66] = 0.0;
		}
		for (int l67 = 0; l67 < 2; l67 = faust_wrap_add(l67, 1)) {
			fRec59[l67] = 0.0;
		}
		for (int l68 = 0; l68 < 32768; l68 = faust_wrap_add(l68, 1)) {
			fVec18[l68] = 0.0;
		}
		for (int l69 = 0; l69 < 2; l69 = faust_wrap_add(l69, 1)) {
			fVec19[l69] = 0.0;
		}
		for (int l70 = 0; l70 < 2; l70 = faust_wrap_add(l70, 1)) {
			fRec50[l70] = 0.0;
		}
		for (int l71 = 0; l71 < 2; l71 = faust_wrap_add(l71, 1)) {
			fRec51[l71] = 0.0;
		}
		for (int l72 = 0; l72 < 2; l72 = faust_wrap_add(l72, 1)) {
			fRec52[l72] = 0.0;
		}
		for (int l73 = 0; l73 < 2; l73 = faust_wrap_add(l73, 1)) {
			fRec53[l73] = 0.0;
		}
		for (int l74 = 0; l74 < 2; l74 = faust_wrap_add(l74, 1)) {
			fRec54[l74] = 0.0;
		}
		for (int l75 = 0; l75 < 2; l75 = faust_wrap_add(l75, 1)) {
			fRec56[l75] = 0.0;
		}
		for (int l76 = 0; l76 < 2; l76 = faust_wrap_add(l76, 1)) {
			fVec20[l76] = 0.0;
		}
		for (int l77 = 0; l77 < 2; l77 = faust_wrap_add(l77, 1)) {
			fRec4[l77] = 0.0;
		}
		for (int l78 = 0; l78 < 2; l78 = faust_wrap_add(l78, 1)) {
			fRec1[l78] = 0.0;
		}
		for (int l79 = 0; l79 < 2; l79 = faust_wrap_add(l79, 1)) {
			fRec2[l79] = 0.0;
		}
		for (int l80 = 0; l80 < 2; l80 = faust_wrap_add(l80, 1)) {
			fRec76[l80] = 0.0;
		}
		for (int l81 = 0; l81 < 2; l81 = faust_wrap_add(l81, 1)) {
			fRec77[l81] = 0.0;
		}
		for (int l82 = 0; l82 < 2; l82 = faust_wrap_add(l82, 1)) {
			fRec75[l82] = 0.0;
		}
		for (int l83 = 0; l83 < 2; l83 = faust_wrap_add(l83, 1)) {
			fRec73[l83] = 0.0;
		}
		for (int l84 = 0; l84 < 2; l84 = faust_wrap_add(l84, 1)) {
			fRec74[l84] = 0.0;
		}
		for (int l85 = 0; l85 < 32768; l85 = faust_wrap_add(l85, 1)) {
			fVec21[l85] = 0.0;
		}
		for (int l86 = 0; l86 < 2; l86 = faust_wrap_add(l86, 1)) {
			fVec22[l86] = 0.0;
		}
		for (int l87 = 0; l87 < 2; l87 = faust_wrap_add(l87, 1)) {
			fRec66[l87] = 0.0;
		}
		for (int l88 = 0; l88 < 2; l88 = faust_wrap_add(l88, 1)) {
			fRec67[l88] = 0.0;
		}
		for (int l89 = 0; l89 < 2; l89 = faust_wrap_add(l89, 1)) {
			fRec68[l89] = 0.0;
		}
		for (int l90 = 0; l90 < 2; l90 = faust_wrap_add(l90, 1)) {
			fRec69[l90] = 0.0;
		}
		for (int l91 = 0; l91 < 2; l91 = faust_wrap_add(l91, 1)) {
			fRec70[l91] = 0.0;
		}
		for (int l92 = 0; l92 < 2; l92 = faust_wrap_add(l92, 1)) {
			fRec72[l92] = 0.0;
		}
		for (int l93 = 0; l93 < 2; l93 = faust_wrap_add(l93, 1)) {
			fRec88[l93] = 0.0;
		}
		for (int l94 = 0; l94 < 2; l94 = faust_wrap_add(l94, 1)) {
			fRec89[l94] = 0.0;
		}
		for (int l95 = 0; l95 < 2; l95 = faust_wrap_add(l95, 1)) {
			fRec87[l95] = 0.0;
		}
		for (int l96 = 0; l96 < 2; l96 = faust_wrap_add(l96, 1)) {
			fRec85[l96] = 0.0;
		}
		for (int l97 = 0; l97 < 2; l97 = faust_wrap_add(l97, 1)) {
			fRec86[l97] = 0.0;
		}
		for (int l98 = 0; l98 < 32768; l98 = faust_wrap_add(l98, 1)) {
			fVec23[l98] = 0.0;
		}
		for (int l99 = 0; l99 < 2; l99 = faust_wrap_add(l99, 1)) {
			fVec24[l99] = 0.0;
		}
		for (int l100 = 0; l100 < 2; l100 = faust_wrap_add(l100, 1)) {
			fRec78[l100] = 0.0;
		}
		for (int l101 = 0; l101 < 2; l101 = faust_wrap_add(l101, 1)) {
			fRec79[l101] = 0.0;
		}
		for (int l102 = 0; l102 < 2; l102 = faust_wrap_add(l102, 1)) {
			fRec80[l102] = 0.0;
		}
		for (int l103 = 0; l103 < 2; l103 = faust_wrap_add(l103, 1)) {
			fRec81[l103] = 0.0;
		}
		for (int l104 = 0; l104 < 2; l104 = faust_wrap_add(l104, 1)) {
			fRec82[l104] = 0.0;
		}
		for (int l105 = 0; l105 < 2; l105 = faust_wrap_add(l105, 1)) {
			fRec84[l105] = 0.0;
		}
		for (int l106 = 0; l106 < 2; l106 = faust_wrap_add(l106, 1)) {
			fRec100[l106] = 0.0;
		}
		for (int l107 = 0; l107 < 2; l107 = faust_wrap_add(l107, 1)) {
			fRec101[l107] = 0.0;
		}
		for (int l108 = 0; l108 < 2; l108 = faust_wrap_add(l108, 1)) {
			fRec99[l108] = 0.0;
		}
		for (int l109 = 0; l109 < 2; l109 = faust_wrap_add(l109, 1)) {
			fRec97[l109] = 0.0;
		}
		for (int l110 = 0; l110 < 2; l110 = faust_wrap_add(l110, 1)) {
			fRec98[l110] = 0.0;
		}
		for (int l111 = 0; l111 < 32768; l111 = faust_wrap_add(l111, 1)) {
			fVec25[l111] = 0.0;
		}
		for (int l112 = 0; l112 < 2; l112 = faust_wrap_add(l112, 1)) {
			fVec26[l112] = 0.0;
		}
		for (int l113 = 0; l113 < 2; l113 = faust_wrap_add(l113, 1)) {
			fRec90[l113] = 0.0;
		}
		for (int l114 = 0; l114 < 2; l114 = faust_wrap_add(l114, 1)) {
			fRec91[l114] = 0.0;
		}
		for (int l115 = 0; l115 < 2; l115 = faust_wrap_add(l115, 1)) {
			fRec92[l115] = 0.0;
		}
		for (int l116 = 0; l116 < 2; l116 = faust_wrap_add(l116, 1)) {
			fRec93[l116] = 0.0;
		}
		for (int l117 = 0; l117 < 2; l117 = faust_wrap_add(l117, 1)) {
			fRec94[l117] = 0.0;
		}
		for (int l118 = 0; l118 < 2; l118 = faust_wrap_add(l118, 1)) {
			fRec96[l118] = 0.0;
		}
		for (int l119 = 0; l119 < 2; l119 = faust_wrap_add(l119, 1)) {
			fRec112[l119] = 0.0;
		}
		for (int l120 = 0; l120 < 2; l120 = faust_wrap_add(l120, 1)) {
			fRec113[l120] = 0.0;
		}
		for (int l121 = 0; l121 < 2; l121 = faust_wrap_add(l121, 1)) {
			fRec111[l121] = 0.0;
		}
		for (int l122 = 0; l122 < 2; l122 = faust_wrap_add(l122, 1)) {
			fRec109[l122] = 0.0;
		}
		for (int l123 = 0; l123 < 2; l123 = faust_wrap_add(l123, 1)) {
			fRec110[l123] = 0.0;
		}
		for (int l124 = 0; l124 < 32768; l124 = faust_wrap_add(l124, 1)) {
			fVec27[l124] = 0.0;
		}
		for (int l125 = 0; l125 < 2; l125 = faust_wrap_add(l125, 1)) {
			fVec28[l125] = 0.0;
		}
		for (int l126 = 0; l126 < 2; l126 = faust_wrap_add(l126, 1)) {
			fRec102[l126] = 0.0;
		}
		for (int l127 = 0; l127 < 2; l127 = faust_wrap_add(l127, 1)) {
			fRec103[l127] = 0.0;
		}
		for (int l128 = 0; l128 < 2; l128 = faust_wrap_add(l128, 1)) {
			fRec104[l128] = 0.0;
		}
		for (int l129 = 0; l129 < 2; l129 = faust_wrap_add(l129, 1)) {
			fRec105[l129] = 0.0;
		}
		for (int l130 = 0; l130 < 2; l130 = faust_wrap_add(l130, 1)) {
			fRec106[l130] = 0.0;
		}
		for (int l131 = 0; l131 < 2; l131 = faust_wrap_add(l131, 1)) {
			fRec108[l131] = 0.0;
		}
		for (int l132 = 0; l132 < 2; l132 = faust_wrap_add(l132, 1)) {
			fVec29[l132] = 0.0;
		}
		for (int l133 = 0; l133 < 2; l133 = faust_wrap_add(l133, 1)) {
			fRec65[l133] = 0.0;
		}
		for (int l134 = 0; l134 < 2; l134 = faust_wrap_add(l134, 1)) {
			fRec63[l134] = 0.0;
		}
		for (int l135 = 0; l135 < 2; l135 = faust_wrap_add(l135, 1)) {
			fRec64[l135] = 0.0;
		}
	}
	
	virtual void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	
	virtual void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	virtual FaustResonateur* clone() {
		return new FaustResonateur(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("SpectralFX");
		ui_interface->addHorizontalSlider("Couleur/Part du résonateur", &fHslider0, FAUSTFLOAT(0.7), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->addHorizontalSlider("Couleur/Saleté", &fHslider1, FAUSTFLOAT(0.3), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->addNumEntry("Résonateur/Accord", &fEntry0, FAUSTFLOAT(2.0), FAUSTFLOAT(0.0), FAUSTFLOAT(6.0), FAUSTFLOAT(1.0));
		ui_interface->addHorizontalSlider("Résonateur/Brillance", &fHslider6, FAUSTFLOAT(0.6), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->addHorizontalSlider("Résonateur/Dérive", &fHslider4, FAUSTFLOAT(0.3), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->addHorizontalSlider("Résonateur/Métal", &fHslider2, FAUSTFLOAT(0.2), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->addHorizontalSlider("Résonateur/Note", &fHslider3, FAUSTFLOAT(4e+01), FAUSTFLOAT(24.0), FAUSTFLOAT(84.0), FAUSTFLOAT(1.0));
		ui_interface->addHorizontalSlider("Résonateur/Résonance", &fHslider5, FAUSTFLOAT(3.0), FAUSTFLOAT(0.2), FAUSTFLOAT(2e+01), FAUSTFLOAT(0.01));
		ui_interface->addCheckButton("Résonateur/Tube", &fCheckbox0);
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		double fSlow0 = static_cast<double>(fHslider0);
		double fSlow1 = 1.0 - fSlow0;
		double fSlow2 = static_cast<double>(fHslider1);
		double fSlow3 = static_cast<double>(fHslider2);
		double fSlow4 = static_cast<double>(fCheckbox0);
		double fSlow5 = fSlow4 + 1.0;
		double fSlow6 = fConst4 / fSlow5;
		double fSlow7 = static_cast<double>(fHslider3);
		int iSlow8 = static_cast<int>(static_cast<double>(fEntry0));
		int iSlow9 = iSlow8 >= 4;
		int iSlow10 = iSlow8 >= 2;
		int iSlow11 = iSlow8 >= 1;
		int iSlow12 = ((iSlow9) ? 12 : ((iSlow10) ? 12 : ((iSlow11) ? 0 : 12)));
		int iSlow13 = faust_wrap_add(iSlow12, -12);
		double fSlow14 = fSlow7 + static_cast<double>(iSlow13) + -69.0;
		double fSlow15 = static_cast<double>(fHslider4);
		double fSlow16 = 1.0 - 2.0 * fSlow4;
		double fSlow17 = 0.006818181818181818 / fSlow5;
		double fSlow18 = static_cast<double>(fHslider5);
		double fSlow19 = static_cast<double>(fHslider6);
		int iSlow20 = iSlow8 >= 3;
		int iSlow21 = iSlow8 >= 6;
		double fSlow22 = ((iSlow9) ? static_cast<double>(((iSlow21) ? 13 : ((iSlow8 >= 5) ? 17 : 15))) : ((iSlow10) ? static_cast<double>(((iSlow20) ? 16 : 19)) : ((iSlow11) ? 12.0 : 12.04)));
		double fSlow23 = fSlow7 + fSlow22 + -81.0;
		double fSlow24 = fSlow22 + -12.0;
		double fSlow25 = ((iSlow9) ? static_cast<double>(((iSlow21) ? 18 : 19)) : ((iSlow10) ? static_cast<double>(((iSlow20) ? 19 : 24)) : ((iSlow11) ? 24.0 : 11.96)));
		double fSlow26 = fSlow7 + fSlow25 + -81.0;
		double fSlow27 = fSlow25 + -12.0;
		double fSlow28 = ((iSlow9) ? static_cast<double>(((iSlow21) ? 23 : 24)) : ((iSlow10) ? static_cast<double>(((iSlow20) ? 24 : 31)) : ((iSlow11) ? 36.0 : 12.02)));
		double fSlow29 = fSlow7 + fSlow28 + -81.0;
		double fSlow30 = fSlow28 + -12.0;
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			double fTemp0 = static_cast<double>(input0[i0]);
			fVec0[0] = fSlow0;
			iVec1[0] = 1;
			fRec0[0] = fConst1 * (std::min<double>(1.7976931348623157e+308, fVec0[1] - fSlow0) + fRec0[1]);
			double fTemp1 = fSlow1 - fRec0[0];
			double fTemp2 = fSlow0 + fRec0[0];
			fVec2[0] = fSlow2;
			fRec3[0] = fConst1 * (std::min<double>(1.7976931348623157e+308, fVec2[1] - fSlow2) + fRec3[1]);
			double fTemp3 = fSlow2 + fRec3[0];
			double fTemp4 = std::tan(std::max<double>(0.0, std::min<double>(fConst2 * (1.6e+04 - 8e+03 * fTemp3), 1.5676547341413067)));
			fVec3[0] = fSlow3;
			fRec12[0] = fConst1 * (std::min<double>(1.7976931348623157e+308, fVec3[1] - fSlow3) + fRec12[1]);
			double fTemp5 = fSlow3 + fRec12[0];
			double fTemp6 = 0.8 * fTemp5;
			double fTemp7 = -1.0 - 4.0 * ((1.0 + fTemp6) / (1.0 - fTemp6));
			fVec4[0] = fSlow7;
			iVec5[0] = iSlow13;
			fRec13[0] = fConst5 * (std::min<double>(1.7976931348623157e+308, fVec4[1] - fSlow7) + fRec13[1]);
			fRec14[0] = fConst6 * (std::min<double>(1.7976931348623157e+308, static_cast<double>(faust_wrap_sub(faust_wrap_add(iVec5[1], 12), iSlow12))) + fRec14[1]);
			double fTemp8 = fRec13[0] + fRec14[0];
			fVec6[0] = fSlow15;
			fRec15[0] = fConst1 * (std::min<double>(1.7976931348623157e+308, fVec6[1] - fSlow15) + fRec15[1]);
			double fTemp9 = fSlow15 + fRec15[0];
			fRec19[0] = fConst12 * fRec20[1] + fConst13 * fRec19[1];
			double fTemp10 = static_cast<double>(faust_wrap_sub(1, iVec1[1]));
			fRec20[0] = fTemp10 - fConst12 * fRec19[1] + fConst13 * fRec20[1];
			iRec21[0] = faust_wrap_add(12345, faust_wrap_mul(1103515245, iRec21[1]));
			double fTemp11 = 4.656612875245797e-10 * static_cast<double>(iRec21[0]);
			fRec18[0] = (((fRec19[1] <= 0.0) & (fRec19[0] > 0.0)) ? fTemp11 : fRec18[1]);
			double fTemp12 = fRec18[0] - (fConst8 * fRec16[1] + fRec17[1]);
			fRec16[0] = fRec16[1] + fConst10 * fTemp12;
			double fTemp13 = fRec16[1] + fConst9 * fTemp12;
			fRec17[0] = fRec17[1] + fConst14 * fTemp13;
			double fTemp14 = std::pow(2.0, 0.08333333333333333 * (fSlow14 + fTemp8 + fTemp9 * (-0.0175 + 0.3 * (fRec17[1] + fConst7 * fTemp13))));
			double fTemp15 = std::max<double>(2.0, fTemp7 + fSlow6 / fTemp14);
			double fTemp16 = -0.999995 + fTemp15;
			double fTemp17 = std::floor(fTemp16);
			double fTemp18 = -2.0 - fTemp17 + fTemp15;
			double fTemp19 = fTemp15 - fTemp17;
			fVec7[0] = fSlow18;
			fRec22[0] = fConst1 * (std::min<double>(1.7976931348623157e+308, fVec7[1] - fSlow18) + fRec22[1]);
			double fTemp20 = fSlow18 + fRec22[0];
			double fTemp21 = std::pow(1e+01, -(fSlow17 / (fTemp14 * fTemp20)));
			double fTemp22 = fSlow16 * fRec11[1] * fTemp21 + fTemp0 * std::sqrt(1.0 - FaustResonateur_faustpower2_f(fTemp21));
			fVec8[IOTA0 & 32767] = fTemp22;
			int iTemp23 = static_cast<int>(std::min<double>(16387.0, std::max<double>(-3.0, fTemp16)));
			double fTemp24 = -1.0 - fTemp17 + fTemp15;
			double fTemp25 = fTemp19 * fTemp24;
			double fTemp26 = (-3.0 - fTemp17 + fTemp15) * (fTemp18 * (0.5 * fTemp19 * fVec8[(faust_wrap_sub(IOTA0, std::min<int>(16387, std::max<int>(0, faust_wrap_add(1, iTemp23))))) & 32767] - 0.16666666666666666 * fVec8[(faust_wrap_sub(IOTA0, std::min<int>(16387, std::max<int>(0, iTemp23)))) & 32767] * fTemp24) - 0.5 * fTemp25 * fVec8[(faust_wrap_sub(IOTA0, std::min<int>(16387, std::max<int>(0, faust_wrap_add(2, iTemp23))))) & 32767]) + 0.16666666666666666 * fTemp25 * fTemp18 * fVec8[(faust_wrap_sub(IOTA0, std::min<int>(16387, std::max<int>(0, faust_wrap_add(3, iTemp23))))) & 32767];
			fVec9[0] = fTemp26;
			fRec5[0] = fVec9[1] - 0.8 * fTemp5 * (fTemp26 - fRec5[1]);
			fRec6[0] = fRec5[1] - 0.8 * fTemp5 * (fRec5[0] - fRec6[1]);
			fRec7[0] = fRec6[1] - 0.8 * fTemp5 * (fRec6[0] - fRec7[1]);
			fRec8[0] = fRec7[1] - 0.8 * fTemp5 * (fRec7[0] - fRec8[1]);
			fVec10[0] = fSlow19;
			fRec23[0] = fConst1 * (std::min<double>(1.7976931348623157e+308, fVec10[1] - fSlow19) + fRec23[1]);
			double fTemp27 = std::tan(std::max<double>(0.0, std::min<double>(fConst2 * std::min<double>(3e+02 * std::pow(2.0, 6.0 * (fSlow19 + fRec23[0])), fConst15), 1.5676547341413067)));
			double fTemp28 = std::min<double>(1.7976931348623157e+308, 1.0 / (1.0 + fTemp27));
			double fTemp29 = fTemp27 * (fRec8[0] - fRec9[1]) * fTemp28;
			fRec9[0] = fRec9[1] + 2.0 * fTemp29;
			double fRec10 = fRec9[1] + fTemp29;
			fRec11[0] = 2.0 * tanh(0.5 * fRec10);
			fVec11[0] = fSlow24;
			fRec31[0] = fConst6 * (std::min<double>(1.7976931348623157e+308, fVec11[1] + 12.0 - fSlow22) + fRec31[1]);
			double fTemp30 = fRec13[0] + fRec31[0];
			fRec35[0] = fConst21 * fRec36[1] + fConst22 * fRec35[1];
			fRec36[0] = fTemp10 - fConst21 * fRec35[1] + fConst22 * fRec36[1];
			fRec34[0] = (((fRec35[1] <= 0.0) & (fRec35[0] > 0.0)) ? fTemp11 : fRec34[1]);
			double fTemp31 = fRec34[0] - (fConst17 * fRec32[1] + fRec33[1]);
			fRec32[0] = fRec32[1] + fConst19 * fTemp31;
			double fTemp32 = fRec32[1] + fConst18 * fTemp31;
			fRec33[0] = fRec33[1] + fConst23 * fTemp32;
			double fTemp33 = std::pow(2.0, 0.08333333333333333 * (fSlow23 + fTemp30 + fTemp9 * (-0.035 + 0.3 * (fRec33[1] + fConst16 * fTemp32))));
			double fTemp34 = std::max<double>(2.0, fTemp7 + fSlow6 / fTemp33);
			double fTemp35 = -0.999995 + fTemp34;
			double fTemp36 = std::floor(fTemp35);
			double fTemp37 = -2.0 - fTemp36 + fTemp34;
			double fTemp38 = fTemp34 - fTemp36;
			double fTemp39 = std::pow(1e+01, -(fSlow17 / (fTemp20 * fTemp33)));
			double fTemp40 = fSlow16 * fRec30[1] * fTemp39 + fTemp0 * std::sqrt(1.0 - FaustResonateur_faustpower2_f(fTemp39));
			fVec12[IOTA0 & 32767] = fTemp40;
			int iTemp41 = static_cast<int>(std::min<double>(16387.0, std::max<double>(-3.0, fTemp35)));
			double fTemp42 = -1.0 - fTemp36 + fTemp34;
			double fTemp43 = fTemp38 * fTemp42;
			double fTemp44 = (-3.0 - fTemp36 + fTemp34) * (fTemp37 * (0.5 * fTemp38 * fVec12[(faust_wrap_sub(IOTA0, std::min<int>(16387, std::max<int>(0, faust_wrap_add(1, iTemp41))))) & 32767] - 0.16666666666666666 * fVec12[(faust_wrap_sub(IOTA0, std::min<int>(16387, std::max<int>(0, iTemp41)))) & 32767] * fTemp42) - 0.5 * fTemp43 * fVec12[(faust_wrap_sub(IOTA0, std::min<int>(16387, std::max<int>(0, faust_wrap_add(2, iTemp41))))) & 32767]) + 0.16666666666666666 * fTemp43 * fTemp37 * fVec12[(faust_wrap_sub(IOTA0, std::min<int>(16387, std::max<int>(0, faust_wrap_add(3, iTemp41))))) & 32767];
			fVec13[0] = fTemp44;
			fRec24[0] = fVec13[1] - 0.8 * fTemp5 * (fTemp44 - fRec24[1]);
			fRec25[0] = fRec24[1] - 0.8 * fTemp5 * (fRec24[0] - fRec25[1]);
			fRec26[0] = fRec25[1] - 0.8 * fTemp5 * (fRec25[0] - fRec26[1]);
			fRec27[0] = fRec26[1] - 0.8 * fTemp5 * (fRec26[0] - fRec27[1]);
			double fTemp45 = fTemp27 * fTemp28;
			double fTemp46 = fTemp45 * (fRec27[0] - fRec28[1]);
			fRec28[0] = fRec28[1] + 2.0 * fTemp46;
			double fRec29 = fRec28[1] + fTemp46;
			fRec30[0] = 2.0 * tanh(0.5 * fRec29);
			fVec14[0] = fSlow27;
			fRec44[0] = fConst6 * (std::min<double>(1.7976931348623157e+308, fVec14[1] + 12.0 - fSlow25) + fRec44[1]);
			double fTemp47 = fRec13[0] + fRec44[0];
			fRec48[0] = fConst29 * fRec49[1] + fConst30 * fRec48[1];
			fRec49[0] = fTemp10 - fConst29 * fRec48[1] + fConst30 * fRec49[1];
			fRec47[0] = (((fRec48[1] <= 0.0) & (fRec48[0] > 0.0)) ? fTemp11 : fRec47[1]);
			double fTemp48 = fRec47[0] - (fConst25 * fRec45[1] + fRec46[1]);
			fRec45[0] = fRec45[1] + fConst27 * fTemp48;
			double fTemp49 = fRec45[1] + fConst26 * fTemp48;
			fRec46[0] = fRec46[1] + fConst31 * fTemp49;
			double fTemp50 = std::pow(2.0, 0.08333333333333333 * (fSlow26 + fTemp47 + fTemp9 * (-0.052500000000000005 + 0.3 * (fRec46[1] + fConst24 * fTemp49))));
			double fTemp51 = std::max<double>(2.0, fTemp7 + fSlow6 / fTemp50);
			double fTemp52 = -0.999995 + fTemp51;
			double fTemp53 = std::floor(fTemp52);
			double fTemp54 = -2.0 - fTemp53 + fTemp51;
			double fTemp55 = fTemp51 - fTemp53;
			double fTemp56 = std::pow(1e+01, -(fSlow17 / (fTemp20 * fTemp50)));
			double fTemp57 = fSlow16 * fRec43[1] * fTemp56 + fTemp0 * std::sqrt(1.0 - FaustResonateur_faustpower2_f(fTemp56));
			fVec15[IOTA0 & 32767] = fTemp57;
			int iTemp58 = static_cast<int>(std::min<double>(16387.0, std::max<double>(-3.0, fTemp52)));
			double fTemp59 = -1.0 - fTemp53 + fTemp51;
			double fTemp60 = fTemp55 * fTemp59;
			double fTemp61 = (-3.0 - fTemp53 + fTemp51) * (fTemp54 * (0.5 * fTemp55 * fVec15[(faust_wrap_sub(IOTA0, std::min<int>(16387, std::max<int>(0, faust_wrap_add(1, iTemp58))))) & 32767] - 0.16666666666666666 * fVec15[(faust_wrap_sub(IOTA0, std::min<int>(16387, std::max<int>(0, iTemp58)))) & 32767] * fTemp59) - 0.5 * fTemp60 * fVec15[(faust_wrap_sub(IOTA0, std::min<int>(16387, std::max<int>(0, faust_wrap_add(2, iTemp58))))) & 32767]) + 0.16666666666666666 * fTemp60 * fTemp54 * fVec15[(faust_wrap_sub(IOTA0, std::min<int>(16387, std::max<int>(0, faust_wrap_add(3, iTemp58))))) & 32767];
			fVec16[0] = fTemp61;
			fRec37[0] = fVec16[1] - 0.8 * fTemp5 * (fTemp61 - fRec37[1]);
			fRec38[0] = fRec37[1] - 0.8 * fTemp5 * (fRec37[0] - fRec38[1]);
			fRec39[0] = fRec38[1] - 0.8 * fTemp5 * (fRec38[0] - fRec39[1]);
			fRec40[0] = fRec39[1] - 0.8 * fTemp5 * (fRec39[0] - fRec40[1]);
			double fTemp62 = fTemp45 * (fRec40[0] - fRec41[1]);
			fRec41[0] = fRec41[1] + 2.0 * fTemp62;
			double fRec42 = fRec41[1] + fTemp62;
			fRec43[0] = 2.0 * tanh(0.5 * fRec42);
			fVec17[0] = fSlow30;
			fRec57[0] = fConst6 * (std::min<double>(1.7976931348623157e+308, fVec17[1] + 12.0 - fSlow28) + fRec57[1]);
			double fTemp63 = fRec13[0] + fRec57[0];
			fRec61[0] = fConst37 * fRec62[1] + fConst38 * fRec61[1];
			fRec62[0] = fTemp10 - fConst37 * fRec61[1] + fConst38 * fRec62[1];
			fRec60[0] = (((fRec61[1] <= 0.0) & (fRec61[0] > 0.0)) ? fTemp11 : fRec60[1]);
			double fTemp64 = fRec60[0] - (fConst33 * fRec58[1] + fRec59[1]);
			fRec58[0] = fRec58[1] + fConst35 * fTemp64;
			double fTemp65 = fRec58[1] + fConst34 * fTemp64;
			fRec59[0] = fRec59[1] + fConst39 * fTemp65;
			double fTemp66 = std::pow(2.0, 0.08333333333333333 * (fSlow29 + fTemp63 + fTemp9 * (-0.07 + 0.3 * (fRec59[1] + fConst32 * fTemp65))));
			double fTemp67 = std::max<double>(2.0, fTemp7 + fSlow6 / fTemp66);
			double fTemp68 = -0.999995 + fTemp67;
			double fTemp69 = std::floor(fTemp68);
			double fTemp70 = -2.0 - fTemp69 + fTemp67;
			double fTemp71 = fTemp67 - fTemp69;
			double fTemp72 = std::pow(1e+01, -(fSlow17 / (fTemp20 * fTemp66)));
			double fTemp73 = fSlow16 * fRec56[1] * fTemp72 + fTemp0 * std::sqrt(1.0 - FaustResonateur_faustpower2_f(fTemp72));
			fVec18[IOTA0 & 32767] = fTemp73;
			int iTemp74 = static_cast<int>(std::min<double>(16387.0, std::max<double>(-3.0, fTemp68)));
			double fTemp75 = -1.0 - fTemp69 + fTemp67;
			double fTemp76 = fTemp71 * fTemp75;
			double fTemp77 = (-3.0 - fTemp69 + fTemp67) * (fTemp70 * (0.5 * fTemp71 * fVec18[(faust_wrap_sub(IOTA0, std::min<int>(16387, std::max<int>(0, faust_wrap_add(1, iTemp74))))) & 32767] - 0.16666666666666666 * fVec18[(faust_wrap_sub(IOTA0, std::min<int>(16387, std::max<int>(0, iTemp74)))) & 32767] * fTemp75) - 0.5 * fTemp76 * fVec18[(faust_wrap_sub(IOTA0, std::min<int>(16387, std::max<int>(0, faust_wrap_add(2, iTemp74))))) & 32767]) + 0.16666666666666666 * fTemp76 * fTemp70 * fVec18[(faust_wrap_sub(IOTA0, std::min<int>(16387, std::max<int>(0, faust_wrap_add(3, iTemp74))))) & 32767];
			fVec19[0] = fTemp77;
			fRec50[0] = fVec19[1] - 0.8 * fTemp5 * (fTemp77 - fRec50[1]);
			fRec51[0] = fRec50[1] - 0.8 * fTemp5 * (fRec50[0] - fRec51[1]);
			fRec52[0] = fRec51[1] - 0.8 * fTemp5 * (fRec51[0] - fRec52[1]);
			fRec53[0] = fRec52[1] - 0.8 * fTemp5 * (fRec52[0] - fRec53[1]);
			double fTemp78 = fTemp45 * (fRec53[0] - fRec54[1]);
			fRec54[0] = fRec54[1] + 2.0 * fTemp78;
			double fRec55 = fRec54[1] + fTemp78;
			fRec56[0] = 2.0 * tanh(0.5 * fRec55);
			double fTemp79 = std::pow(1e+01, 1.5 * fTemp3);
			double fTemp80 = 0.25 * fTemp3;
			double fTemp81 = tanh(fTemp80);
			double fTemp82 = std::pow(fTemp79, 0.55);
			double fTemp83 = (tanh(0.5 * (fRec11[0] + fRec30[0] + fRec43[0] + fRec56[0]) * fTemp79 + fTemp80) - fTemp81) / fTemp82;
			fVec20[0] = fTemp83;
			fRec4[0] = fConst3 * fRec4[1] + fTemp83 - fVec20[1];
			double fTemp84 = 1.414213562373095 + fTemp4;
			double fTemp85 = std::min<double>(1.7976931348623157e+308, 1.0 / (1.0 + fTemp4 * fTemp84));
			double fTemp86 = fTemp4 * (fRec4[0] - (fTemp84 * fRec1[1] + fRec2[1])) * fTemp85;
			fRec1[0] = fRec1[1] + 2.0 * fTemp86;
			double fTemp87 = fTemp4 * (fRec1[1] + fTemp86);
			fRec2[0] = fRec2[1] + 2.0 * fTemp87;
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp0 * fTemp1 + fTemp2 * (fRec2[1] + fTemp87));
			double fTemp88 = static_cast<double>(input1[i0]);
			fRec76[0] = fConst45 * fRec77[1] + fConst46 * fRec76[1];
			fRec77[0] = fTemp10 - fConst45 * fRec76[1] + fConst46 * fRec77[1];
			fRec75[0] = (((fRec76[1] <= 0.0) & (fRec76[0] > 0.0)) ? fTemp11 : fRec75[1]);
			double fTemp89 = fRec75[0] - (fConst41 * fRec73[1] + fRec74[1]);
			fRec73[0] = fRec73[1] + fConst43 * fTemp89;
			double fTemp90 = fRec73[1] + fConst42 * fTemp89;
			fRec74[0] = fRec74[1] + fConst47 * fTemp90;
			double fTemp91 = std::pow(2.0, 0.08333333333333333 * (fSlow14 + fTemp8 + fTemp9 * (0.0175 + 0.3 * (fRec74[1] + fConst40 * fTemp90))));
			double fTemp92 = std::max<double>(2.0, fTemp7 + fSlow6 / fTemp91);
			double fTemp93 = -0.999995 + fTemp92;
			double fTemp94 = std::floor(fTemp93);
			double fTemp95 = -2.0 - fTemp94 + fTemp92;
			double fTemp96 = fTemp92 - fTemp94;
			double fTemp97 = std::pow(1e+01, -(fSlow17 / (fTemp20 * fTemp91)));
			double fTemp98 = fSlow16 * fRec72[1] * fTemp97 + fTemp88 * std::sqrt(1.0 - FaustResonateur_faustpower2_f(fTemp97));
			fVec21[IOTA0 & 32767] = fTemp98;
			int iTemp99 = static_cast<int>(std::min<double>(16387.0, std::max<double>(-3.0, fTemp93)));
			double fTemp100 = -1.0 - fTemp94 + fTemp92;
			double fTemp101 = fTemp96 * fTemp100;
			double fTemp102 = (-3.0 - fTemp94 + fTemp92) * (fTemp95 * (0.5 * fTemp96 * fVec21[(faust_wrap_sub(IOTA0, std::min<int>(16387, std::max<int>(0, faust_wrap_add(1, iTemp99))))) & 32767] - 0.16666666666666666 * fVec21[(faust_wrap_sub(IOTA0, std::min<int>(16387, std::max<int>(0, iTemp99)))) & 32767] * fTemp100) - 0.5 * fTemp101 * fVec21[(faust_wrap_sub(IOTA0, std::min<int>(16387, std::max<int>(0, faust_wrap_add(2, iTemp99))))) & 32767]) + 0.16666666666666666 * fTemp101 * fTemp95 * fVec21[(faust_wrap_sub(IOTA0, std::min<int>(16387, std::max<int>(0, faust_wrap_add(3, iTemp99))))) & 32767];
			fVec22[0] = fTemp102;
			fRec66[0] = fVec22[1] - 0.8 * fTemp5 * (fTemp102 - fRec66[1]);
			fRec67[0] = fRec66[1] - 0.8 * fTemp5 * (fRec66[0] - fRec67[1]);
			fRec68[0] = fRec67[1] - 0.8 * fTemp5 * (fRec67[0] - fRec68[1]);
			fRec69[0] = fRec68[1] - 0.8 * fTemp5 * (fRec68[0] - fRec69[1]);
			double fTemp103 = fTemp45 * (fRec69[0] - fRec70[1]);
			fRec70[0] = fRec70[1] + 2.0 * fTemp103;
			double fRec71 = fRec70[1] + fTemp103;
			fRec72[0] = 2.0 * tanh(0.5 * fRec71);
			fRec88[0] = fConst53 * fRec89[1] + fConst54 * fRec88[1];
			fRec89[0] = fTemp10 - fConst53 * fRec88[1] + fConst54 * fRec89[1];
			fRec87[0] = (((fRec88[1] <= 0.0) & (fRec88[0] > 0.0)) ? fTemp11 : fRec87[1]);
			double fTemp104 = fRec87[0] - (fConst49 * fRec85[1] + fRec86[1]);
			fRec85[0] = fRec85[1] + fConst51 * fTemp104;
			double fTemp105 = fRec85[1] + fConst50 * fTemp104;
			fRec86[0] = fRec86[1] + fConst55 * fTemp105;
			double fTemp106 = std::pow(2.0, 0.08333333333333333 * (fSlow23 + fTemp30 + fTemp9 * (0.035 + 0.3 * (fRec86[1] + fConst48 * fTemp105))));
			double fTemp107 = std::max<double>(2.0, fTemp7 + fSlow6 / fTemp106);
			double fTemp108 = -0.999995 + fTemp107;
			double fTemp109 = std::floor(fTemp108);
			double fTemp110 = -2.0 - fTemp109 + fTemp107;
			double fTemp111 = fTemp107 - fTemp109;
			double fTemp112 = std::pow(1e+01, -(fSlow17 / (fTemp20 * fTemp106)));
			double fTemp113 = fSlow16 * fRec84[1] * fTemp112 + fTemp88 * std::sqrt(1.0 - FaustResonateur_faustpower2_f(fTemp112));
			fVec23[IOTA0 & 32767] = fTemp113;
			int iTemp114 = static_cast<int>(std::min<double>(16387.0, std::max<double>(-3.0, fTemp108)));
			double fTemp115 = -1.0 - fTemp109 + fTemp107;
			double fTemp116 = fTemp111 * fTemp115;
			double fTemp117 = (-3.0 - fTemp109 + fTemp107) * (fTemp110 * (0.5 * fTemp111 * fVec23[(faust_wrap_sub(IOTA0, std::min<int>(16387, std::max<int>(0, faust_wrap_add(1, iTemp114))))) & 32767] - 0.16666666666666666 * fVec23[(faust_wrap_sub(IOTA0, std::min<int>(16387, std::max<int>(0, iTemp114)))) & 32767] * fTemp115) - 0.5 * fTemp116 * fVec23[(faust_wrap_sub(IOTA0, std::min<int>(16387, std::max<int>(0, faust_wrap_add(2, iTemp114))))) & 32767]) + 0.16666666666666666 * fTemp116 * fTemp110 * fVec23[(faust_wrap_sub(IOTA0, std::min<int>(16387, std::max<int>(0, faust_wrap_add(3, iTemp114))))) & 32767];
			fVec24[0] = fTemp117;
			fRec78[0] = fVec24[1] - 0.8 * fTemp5 * (fTemp117 - fRec78[1]);
			fRec79[0] = fRec78[1] - 0.8 * fTemp5 * (fRec78[0] - fRec79[1]);
			fRec80[0] = fRec79[1] - 0.8 * fTemp5 * (fRec79[0] - fRec80[1]);
			fRec81[0] = fRec80[1] - 0.8 * fTemp5 * (fRec80[0] - fRec81[1]);
			double fTemp118 = fTemp45 * (fRec81[0] - fRec82[1]);
			fRec82[0] = fRec82[1] + 2.0 * fTemp118;
			double fRec83 = fRec82[1] + fTemp118;
			fRec84[0] = 2.0 * tanh(0.5 * fRec83);
			fRec100[0] = fConst61 * fRec101[1] + fConst62 * fRec100[1];
			fRec101[0] = fTemp10 - fConst61 * fRec100[1] + fConst62 * fRec101[1];
			fRec99[0] = (((fRec100[1] <= 0.0) & (fRec100[0] > 0.0)) ? fTemp11 : fRec99[1]);
			double fTemp119 = fRec99[0] - (fConst57 * fRec97[1] + fRec98[1]);
			fRec97[0] = fRec97[1] + fConst59 * fTemp119;
			double fTemp120 = fRec97[1] + fConst58 * fTemp119;
			fRec98[0] = fRec98[1] + fConst63 * fTemp120;
			double fTemp121 = std::pow(2.0, 0.08333333333333333 * (fSlow26 + fTemp47 + fTemp9 * (0.052500000000000005 + 0.3 * (fRec98[1] + fConst56 * fTemp120))));
			double fTemp122 = std::max<double>(2.0, fTemp7 + fSlow6 / fTemp121);
			double fTemp123 = -0.999995 + fTemp122;
			double fTemp124 = std::floor(fTemp123);
			double fTemp125 = -2.0 - fTemp124 + fTemp122;
			double fTemp126 = fTemp122 - fTemp124;
			double fTemp127 = std::pow(1e+01, -(fSlow17 / (fTemp20 * fTemp121)));
			double fTemp128 = fSlow16 * fRec96[1] * fTemp127 + fTemp88 * std::sqrt(1.0 - FaustResonateur_faustpower2_f(fTemp127));
			fVec25[IOTA0 & 32767] = fTemp128;
			int iTemp129 = static_cast<int>(std::min<double>(16387.0, std::max<double>(-3.0, fTemp123)));
			double fTemp130 = -1.0 - fTemp124 + fTemp122;
			double fTemp131 = fTemp126 * fTemp130;
			double fTemp132 = (-3.0 - fTemp124 + fTemp122) * (fTemp125 * (0.5 * fTemp126 * fVec25[(faust_wrap_sub(IOTA0, std::min<int>(16387, std::max<int>(0, faust_wrap_add(1, iTemp129))))) & 32767] - 0.16666666666666666 * fVec25[(faust_wrap_sub(IOTA0, std::min<int>(16387, std::max<int>(0, iTemp129)))) & 32767] * fTemp130) - 0.5 * fTemp131 * fVec25[(faust_wrap_sub(IOTA0, std::min<int>(16387, std::max<int>(0, faust_wrap_add(2, iTemp129))))) & 32767]) + 0.16666666666666666 * fTemp131 * fTemp125 * fVec25[(faust_wrap_sub(IOTA0, std::min<int>(16387, std::max<int>(0, faust_wrap_add(3, iTemp129))))) & 32767];
			fVec26[0] = fTemp132;
			fRec90[0] = fVec26[1] - 0.8 * fTemp5 * (fTemp132 - fRec90[1]);
			fRec91[0] = fRec90[1] - 0.8 * fTemp5 * (fRec90[0] - fRec91[1]);
			fRec92[0] = fRec91[1] - 0.8 * fTemp5 * (fRec91[0] - fRec92[1]);
			fRec93[0] = fRec92[1] - 0.8 * fTemp5 * (fRec92[0] - fRec93[1]);
			double fTemp133 = fTemp45 * (fRec93[0] - fRec94[1]);
			fRec94[0] = fRec94[1] + 2.0 * fTemp133;
			double fRec95 = fRec94[1] + fTemp133;
			fRec96[0] = 2.0 * tanh(0.5 * fRec95);
			fRec112[0] = fConst69 * fRec113[1] + fConst70 * fRec112[1];
			fRec113[0] = fTemp10 - fConst69 * fRec112[1] + fConst70 * fRec113[1];
			fRec111[0] = (((fRec112[1] <= 0.0) & (fRec112[0] > 0.0)) ? fTemp11 : fRec111[1]);
			double fTemp134 = fRec111[0] - (fConst65 * fRec109[1] + fRec110[1]);
			fRec109[0] = fRec109[1] + fConst67 * fTemp134;
			double fTemp135 = fRec109[1] + fConst66 * fTemp134;
			fRec110[0] = fRec110[1] + fConst71 * fTemp135;
			double fTemp136 = std::pow(2.0, 0.08333333333333333 * (fSlow29 + fTemp63 + fTemp9 * (0.07 + 0.3 * (fRec110[1] + fConst64 * fTemp135))));
			double fTemp137 = std::max<double>(2.0, fTemp7 + fSlow6 / fTemp136);
			double fTemp138 = -0.999995 + fTemp137;
			double fTemp139 = std::floor(fTemp138);
			double fTemp140 = -2.0 - fTemp139 + fTemp137;
			double fTemp141 = fTemp137 - fTemp139;
			double fTemp142 = std::pow(1e+01, -(fSlow17 / (fTemp20 * fTemp136)));
			double fTemp143 = fSlow16 * fRec108[1] * fTemp142 + fTemp88 * std::sqrt(1.0 - FaustResonateur_faustpower2_f(fTemp142));
			fVec27[IOTA0 & 32767] = fTemp143;
			int iTemp144 = static_cast<int>(std::min<double>(16387.0, std::max<double>(-3.0, fTemp138)));
			double fTemp145 = -1.0 - fTemp139 + fTemp137;
			double fTemp146 = fTemp141 * fTemp145;
			double fTemp147 = (-3.0 - fTemp139 + fTemp137) * (fTemp140 * (0.5 * fTemp141 * fVec27[(faust_wrap_sub(IOTA0, std::min<int>(16387, std::max<int>(0, faust_wrap_add(1, iTemp144))))) & 32767] - 0.16666666666666666 * fVec27[(faust_wrap_sub(IOTA0, std::min<int>(16387, std::max<int>(0, iTemp144)))) & 32767] * fTemp145) - 0.5 * fTemp146 * fVec27[(faust_wrap_sub(IOTA0, std::min<int>(16387, std::max<int>(0, faust_wrap_add(2, iTemp144))))) & 32767]) + 0.16666666666666666 * fTemp146 * fTemp140 * fVec27[(faust_wrap_sub(IOTA0, std::min<int>(16387, std::max<int>(0, faust_wrap_add(3, iTemp144))))) & 32767];
			fVec28[0] = fTemp147;
			fRec102[0] = fVec28[1] - 0.8 * fTemp5 * (fTemp147 - fRec102[1]);
			fRec103[0] = fRec102[1] - 0.8 * fTemp5 * (fRec102[0] - fRec103[1]);
			fRec104[0] = fRec103[1] - 0.8 * fTemp5 * (fRec103[0] - fRec104[1]);
			fRec105[0] = fRec104[1] - 0.8 * fTemp5 * (fRec104[0] - fRec105[1]);
			double fTemp148 = fTemp45 * (fRec105[0] - fRec106[1]);
			fRec106[0] = fRec106[1] + 2.0 * fTemp148;
			double fRec107 = fRec106[1] + fTemp148;
			fRec108[0] = 2.0 * tanh(0.5 * fRec107);
			double fTemp149 = (tanh(fTemp80 + 0.5 * fTemp79 * (fRec72[0] + fRec84[0] + fRec96[0] + fRec108[0])) - fTemp81) / fTemp82;
			fVec29[0] = fTemp149;
			fRec65[0] = fConst3 * fRec65[1] + fTemp149 - fVec29[1];
			double fTemp150 = fTemp4 * fTemp85 * (fRec65[0] - (fTemp84 * fRec63[1] + fRec64[1]));
			fRec63[0] = fRec63[1] + 2.0 * fTemp150;
			double fTemp151 = fTemp4 * (fRec63[1] + fTemp150);
			fRec64[0] = fRec64[1] + 2.0 * fTemp151;
			output1[i0] = static_cast<FAUSTFLOAT>(fTemp88 * fTemp1 + fTemp2 * (fRec64[1] + fTemp151));
			fVec0[1] = fVec0[0];
			iVec1[1] = iVec1[0];
			fRec0[1] = fRec0[0];
			fVec2[1] = fVec2[0];
			fRec3[1] = fRec3[0];
			fVec3[1] = fVec3[0];
			fRec12[1] = fRec12[0];
			fVec4[1] = fVec4[0];
			iVec5[1] = iVec5[0];
			fRec13[1] = fRec13[0];
			fRec14[1] = fRec14[0];
			fVec6[1] = fVec6[0];
			fRec15[1] = fRec15[0];
			fRec19[1] = fRec19[0];
			fRec20[1] = fRec20[0];
			iRec21[1] = iRec21[0];
			fRec18[1] = fRec18[0];
			fRec16[1] = fRec16[0];
			fRec17[1] = fRec17[0];
			fVec7[1] = fVec7[0];
			fRec22[1] = fRec22[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fVec9[1] = fVec9[0];
			fRec5[1] = fRec5[0];
			fRec6[1] = fRec6[0];
			fRec7[1] = fRec7[0];
			fRec8[1] = fRec8[0];
			fVec10[1] = fVec10[0];
			fRec23[1] = fRec23[0];
			fRec9[1] = fRec9[0];
			fRec11[1] = fRec11[0];
			fVec11[1] = fVec11[0];
			fRec31[1] = fRec31[0];
			fRec35[1] = fRec35[0];
			fRec36[1] = fRec36[0];
			fRec34[1] = fRec34[0];
			fRec32[1] = fRec32[0];
			fRec33[1] = fRec33[0];
			fVec13[1] = fVec13[0];
			fRec24[1] = fRec24[0];
			fRec25[1] = fRec25[0];
			fRec26[1] = fRec26[0];
			fRec27[1] = fRec27[0];
			fRec28[1] = fRec28[0];
			fRec30[1] = fRec30[0];
			fVec14[1] = fVec14[0];
			fRec44[1] = fRec44[0];
			fRec48[1] = fRec48[0];
			fRec49[1] = fRec49[0];
			fRec47[1] = fRec47[0];
			fRec45[1] = fRec45[0];
			fRec46[1] = fRec46[0];
			fVec16[1] = fVec16[0];
			fRec37[1] = fRec37[0];
			fRec38[1] = fRec38[0];
			fRec39[1] = fRec39[0];
			fRec40[1] = fRec40[0];
			fRec41[1] = fRec41[0];
			fRec43[1] = fRec43[0];
			fVec17[1] = fVec17[0];
			fRec57[1] = fRec57[0];
			fRec61[1] = fRec61[0];
			fRec62[1] = fRec62[0];
			fRec60[1] = fRec60[0];
			fRec58[1] = fRec58[0];
			fRec59[1] = fRec59[0];
			fVec19[1] = fVec19[0];
			fRec50[1] = fRec50[0];
			fRec51[1] = fRec51[0];
			fRec52[1] = fRec52[0];
			fRec53[1] = fRec53[0];
			fRec54[1] = fRec54[0];
			fRec56[1] = fRec56[0];
			fVec20[1] = fVec20[0];
			fRec4[1] = fRec4[0];
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
			fRec76[1] = fRec76[0];
			fRec77[1] = fRec77[0];
			fRec75[1] = fRec75[0];
			fRec73[1] = fRec73[0];
			fRec74[1] = fRec74[0];
			fVec22[1] = fVec22[0];
			fRec66[1] = fRec66[0];
			fRec67[1] = fRec67[0];
			fRec68[1] = fRec68[0];
			fRec69[1] = fRec69[0];
			fRec70[1] = fRec70[0];
			fRec72[1] = fRec72[0];
			fRec88[1] = fRec88[0];
			fRec89[1] = fRec89[0];
			fRec87[1] = fRec87[0];
			fRec85[1] = fRec85[0];
			fRec86[1] = fRec86[0];
			fVec24[1] = fVec24[0];
			fRec78[1] = fRec78[0];
			fRec79[1] = fRec79[0];
			fRec80[1] = fRec80[0];
			fRec81[1] = fRec81[0];
			fRec82[1] = fRec82[0];
			fRec84[1] = fRec84[0];
			fRec100[1] = fRec100[0];
			fRec101[1] = fRec101[0];
			fRec99[1] = fRec99[0];
			fRec97[1] = fRec97[0];
			fRec98[1] = fRec98[0];
			fVec26[1] = fVec26[0];
			fRec90[1] = fRec90[0];
			fRec91[1] = fRec91[0];
			fRec92[1] = fRec92[0];
			fRec93[1] = fRec93[0];
			fRec94[1] = fRec94[0];
			fRec96[1] = fRec96[0];
			fRec112[1] = fRec112[0];
			fRec113[1] = fRec113[0];
			fRec111[1] = fRec111[0];
			fRec109[1] = fRec109[0];
			fRec110[1] = fRec110[0];
			fVec28[1] = fVec28[0];
			fRec102[1] = fRec102[0];
			fRec103[1] = fRec103[0];
			fRec104[1] = fRec104[0];
			fRec105[1] = fRec105[0];
			fRec106[1] = fRec106[0];
			fRec108[1] = fRec108[0];
			fVec29[1] = fVec29[0];
			fRec65[1] = fRec65[0];
			fRec63[1] = fRec63[0];
			fRec64[1] = fRec64[0];
		}
	}

};

#endif
