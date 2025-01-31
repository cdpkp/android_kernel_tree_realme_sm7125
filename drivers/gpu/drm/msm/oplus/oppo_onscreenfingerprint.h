/***************************************************************
** Copyright (C),  2020,  OPPO Mobile Comm Corp.,  Ltd
** VENDOR_EDIT
** File : oppo_onscreenfingerprint.h
** Description : oppo onscreenfingerprint feature
** Version : 1.0
** Date : 2020/04/15
**
** ------------------------------- Revision History: -----------
**  <author>        <data>        <version >        <desc>
**   Qianxu         2020/04/15        1.0           Build this moudle
******************************************************************/
#ifndef _OPPO_ONSCREENFINGERPRINT_H_
#define _OPPO_ONSCREENFINGERPRINT_H_

#include <drm/drm_crtc.h>
#include "dsi_panel.h"
#include "dsi_defs.h"
#include "dsi_parser.h"
#include "sde_encoder_phys.h"


#define FFL_FP_LEVEL 150

enum CUST_ALPHA_ENUM{
	CUST_A_NO = 0,
	CUST_A_TRANS,  /* alpha = 0, transparent */
	CUST_A_OPAQUE, /* alpha = 255, opaque */
};

void oppo_set_aod_dim_alpha(int cust);

int oppo_get_panel_brightness(void);

int oppo_get_panel_power_mode(void);

int dsi_panel_parse_oppo_fod_config(struct dsi_panel *panel);

int dsi_panel_parse_oppo_config(struct dsi_panel *panel);

int dsi_panel_parse_oppo_mode_config(struct dsi_display_mode *mode, struct dsi_parser_utils *utils);

bool sde_crtc_get_dimlayer_mode(struct drm_crtc_state *crtc_state);

bool sde_crtc_get_fingerprint_mode(struct drm_crtc_state *crtc_state);

bool sde_crtc_get_fingerprint_pressed(struct drm_crtc_state *crtc_state);

bool sde_connector_get_fppress_mode(struct drm_connector *connector);

bool sde_connector_get_fp_mode(struct drm_connector *connector);

int sde_crtc_set_onscreenfinger_defer_sync(struct drm_crtc_state *crtc_state, bool defer_sync);

int sde_crtc_config_fingerprint_dim_layer(struct drm_crtc_state *crtc_state, int stage);

bool is_skip_pcc(struct drm_crtc *crtc);

bool sde_cp_crtc_update_pcc(struct drm_crtc *crtc);

bool _sde_encoder_setup_dither_for_onscreenfingerprint(struct sde_encoder_phys *phys,
						  void *dither_cfg, int len);

int sde_plane_check_fingerprint_layer(const struct drm_plane_state *drm_state);

int oplus_display_panel_get_dimlayer_hbm(void *data);
int oppo_ofp_set_fp_type(void *buf);
int oppo_ofp_get_fp_type(void *buf);
ssize_t oppo_ofp_set_fp_type_attr(struct device *dev,
				struct device_attribute *attr,
				const char *buf, size_t count);
ssize_t oppo_ofp_get_fp_type_attr(struct device *dev,
				struct device_attribute *attr, char *buf);
#endif /*_OPPO_ONSCREENFINGERPRINT_H_*/
