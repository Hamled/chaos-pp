<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:output method="xml" indent="yes" encoding="UTF-8"/>

<xsl:param name="source"/>

<xsl:template match="/library">
	<library>
		<xsl:apply-templates>
			<xsl:with-param name="path" select="''"/>
		</xsl:apply-templates>
	</library>
</xsl:template>

<xsl:template match="/library//directory">
	<xsl:param name="path"/>
	<xsl:apply-templates>
		<xsl:with-param name="path" select="concat($path, @name, '/')"/>
	</xsl:apply-templates>
</xsl:template>

<xsl:template match="/library//document">
	<xsl:param name="path"/>
	<document path="{$path}{@id}">
		<xsl:copy-of select="item"/>
	</document>
</xsl:template>

<xsl:template match="/library//header">
	<xsl:param name="path"/>
	<header name="{$path}{@name}"/>
	<xsl:apply-templates select="document(concat($source, '/', $path, substring-before(@name, '.'), '.xml'))/header/macro">
		<xsl:with-param name="path" select="concat($path, @name)"/>
	</xsl:apply-templates>
</xsl:template>

<xsl:template match="/header/macro | /header/macro//derivative">
	<xsl:param name="path"/>
	<xsl:param name="type" select="'PRIMARY'"/>
	<xsl:choose>
		<xsl:when test="@display">
			<macro id="{@id}" header="{$path}" type="{$type}" display="{@display}">
				<xsl:call-template name="make-groups"/>
			</macro>
		</xsl:when>
		<xsl:otherwise>
			<macro id="{@id}" header="{$path}" type="{$type}">
				<xsl:call-template name="make-groups"/>
			</macro>
		</xsl:otherwise>
	</xsl:choose>
	<xsl:apply-templates select="derivative | alias">
		<xsl:with-param name="path" select="$path"/>
		<xsl:with-param name="type" select="'SECONDARY'"/>
	</xsl:apply-templates>
</xsl:template>

<xsl:template match="/header/macro//alias">
	<xsl:param name="path"/>
	<alias id="{@id}" aliased-id="{../@id}" header="{$path}" type="'ALIAS'"/>
</xsl:template>

<xsl:template name="make-groups">
	<xsl:param name="string" select="string(@group)"/>
	<xsl:choose>
		<xsl:when test="contains($string, ' ')">
			<group id="{substring-before($string, ' ')}"/>
			<xsl:call-template name="make-groups">
				<xsl:with-param name="string" select="substring-after($string, ' ')"/>
			</xsl:call-template>
		</xsl:when>
		<xsl:when test="string-length($string)">
			<group id="{$string}"/>
		</xsl:when>
	</xsl:choose>
</xsl:template>

</xsl:stylesheet>
