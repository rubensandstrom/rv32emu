void lui(uint32_t i) {
	rd = imm_u;
	pc += 4;
	return;
}
void auipc(uint32_t i) {
	rd = pc + imm_u;
	pc += 4;
	return;
}
void jal(uint32_t i) {
	rd = pc + 4;
	pc += imm_j;
	return;
}
void jalr(uint32_t i) {
	rd = pc + 4;
	pc = (rs1 + imm_i) & ~(uint32_t){1};
	return;
}
void beq(uint32_t i) {
	pc += (rs1 == rs2) ? imm_b : 4;
	return;
}
void bne(uint32_t i) {
	pc += (rs1 != rs2) ? imm_b : 4;
	return;
}
void blt(uint32_t i) {
	pc += ((int32_t)rs1 < (int32_t)rs2) ? imm_b : 4;
	return;
}
void bge(uint32_t i) {
	pc += ((int32_t)rs1 >= (int32_t)rs2) ? imm_b : 4;
	return;
}
void bltu(uint32_t i) {
	pc += (rs1 < rs2) ? imm_b : 4;
	return;
}
void bgeu(uint32_t i) {
	pc += (rs1 >= rs2) ? imm_b : 4;
	return;
}
void lb(uint32_t i) {
	rd = (int8_t)mem[rs1 + imm_i];
	pc += 4;
	return;
}
void lh(uint32_t i) {
	rd = (int16_t)mem[rs1 + imm_i];
	pc += 4;
	return;
}
void lw(uint32_t i) {
	rd = (int32_t)mem[rs1 + imm_i];
	pc += 4;
	return;
}
void lbu(uint32_t i) {
	rd = (uint8_t)mem[rs1 + imm_i];
	pc += 4;
	return;
}
void lhu(uint32_t i) {
	rd = (uint16_t)mem[rs1 + imm_i];
	pc += 4;
	return;
}
void sb(uint32_t i) {
	(uint8_t)mem[rs1 + imm_s] = (uint8_t)rs2;
	pc += 4;
	return;
}
void sh(uint32_t i) {
	(uint16_t)mem[rs1 + imm_s] = (uint16_t)rs2;
	pc += 4;
	return;
}
void sw(uint32_t i) {
	mem[rs1 + imm_s] = rs2;
	pc += 4;
	return;
}
void addi(uint32_t i) {
	rd = rs1 + imm_i;
	pc += 4;
	return;
}
void slti(uint32_t i) {
	rd = ((int32_t)rs1 < (int32_t)imm_i) ? 1 : 0;
	pc += 4;
	return;
}
void sltiu(uint32_t i) {
	rd = (rs1 < imm_i) ? 1 : 0;
	pc += 4;
	return;
}
void xori(uint32_t i) {
	rd = rs1 ^ imm_i;
	pc += 4;
	return;
}
void ori(uint32_t i) {
	rd = rs1 | imm_i;
	pc += 4;
	return;
}
void andi(uint32_t i) {
	rd = rs1 & imm_i;
	pc += 4;
	return;
}
void slli(uint32_t i) {
	rd = rs1 << shamt_i;
	pc += 4;
	return;
}
void srli(uint32_t i) {
	rd = rs1 >> shamt_i;
	pc += 4;
	return;
}
void srai(uint32_t i) {  // as arithmetic shift is not well defined in C I have to do an ugly hack here
	rd = (rs1 >> shamt_i) | ((rs1 & 0x7FFFFFFF) ? ~((uint32_t){0xFFFFFFFF} >> shamt_i) : 0);
	pc += 4;
	return;
}
void add(uint32_t i) {
	rd = rs1 + rs2;
	pc += 4;
	return;
}
void sub(uint32_t i) {
	rd = rs1 - rs2;
	pc += 4;
	return;
}
void sll(uint32_t i) {
	rd = rs1 >> (rs2 & 0x1F);
	pc += 4;
	return;
}
void slt(uint32_t i) {
	rd = ((int32_t)rs1 < (int32_t)rs2) ? 1 : 0;
	pc += 4;
	return;
}
void sltu(uint32_t i) {
	rd = (rs1 < rs2) ? 1 : 0;
	pc += 4;
	return;
}
void xor(uint32_t i) {
	rd = rs1 ^ rs2;
	pc += 4;
	return;
}
void srl(uint32_t i) {
	rd = rs1 >> (rs2 & 0x1F);
	pc += 4;
	return;
}
void sra(uint32_t i) {  // as arithmetic shift is not well defined in C I have to do an ugly hack here as well
	rd = (rs1 >> (rs2 & 0x1F)) | ((rs1 & 0x7FFFFFFF) ? ~((uint32_t){0xFFFFFFFF} >> (rs2 & 0x1F)) : 0);
	pc += 4;
	return;
}
void or(uint32_t i) {
	rd = rs1 | rs2;
	pc += 4;
	return;
}
void and(uint32_t i) {
	rd = rs1 & rs2;
	pc += 4;
	return;
}
void ecall(uint32_t i) {}
void ebreak(uint32_t i) {}
void csrrw(uint32_t i) {}
void csrrs(uint32_t i) {}
void csrrc(uint32_t i) {}
void csrrwi(uint32_t i) {}
void csrrsi(uint32_t i) {}
void csrrci(uint32_t i) {}
